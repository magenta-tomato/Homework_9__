#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>
#include <iostream>
#include <fstream>
using namespace std;

struct DATA
{
	DATA(string v) : val(v) {}
	string val;
	bool file = false;
	bool console = false;
};

#define FILE_THREAD 1
#define CONSOLE_THREAD 2

class WriteThreads
{
public:
	void get(vector<string> v)
	{
		if (!isStart) {
			start();
			isStart = true;
		}
		mtx.lock();
		for (const auto& i : v) {
			data.push_back(DATA(i));
		}
		//std::this_thread::sleep_for(std::chrono::seconds(1));
		cv.notify_all();
		mtx.unlock();
	}

	void noMoreDataAhead()
	{
		mtx.lock();
		dataAhead = false;
		cv.notify_all();
		mtx.unlock();
	}

	void wait()
	{
		t1.join();
		t2.join();
		t3.join();
	}

private:
	thread t1;
	thread t2;
	thread t3;
	vector<DATA> data;
	mutex mtx;
	condition_variable cv;
	bool isStart = false;
	bool dataAhead = true;
	bool allStopped = false;

	void start()
	{
		t1 = std::thread(&WriteThreads::loop, this, FILE_THREAD);
		t2 = std::thread(&WriteThreads::loop, this, FILE_THREAD);
		t3 = std::thread(&WriteThreads::loop, this, CONSOLE_THREAD);
	}

	void loop(int threadType)
	{
		while (!allStopped) {
			std::unique_lock<std::mutex> ulock(mtx);
			cv.wait(ulock, [this] {return (data.size() || !dataAhead); });
			cv.wait(ulock);

			for (auto it = data.begin(); it != data.end();) {
				if (!(*it).file && threadType == FILE_THREAD) {
					(*it).file = true;
					writeFile(it->val);
				}
				if (!(*it).console && threadType == CONSOLE_THREAD) {
					(*it).console = true;
					writeConsole(it->val);
				}
				if ((*it).file == true && (*it).console == true ){
					it = data.erase(it);
				}
				else {
					it++;
				}
			}
		}
		// больше данных не ожидается
		if (!dataAhead && data.empty()) {
			allStopped = true;
		}
	}

	// запись в файл
	void writeFile( string res )
	{
		string fileName = "bulk" + getTime() + ".log";
		ofstream file = ofstream(fileName, ios::app);
		if (!file.is_open()) {
			throw std::runtime_error("Error open file\n");
		}
		file << res << endl;
		file.close();
	}

	void writeConsole( string res ) {
		cout << res << endl;
	}

	// время
	string getTime() {
		using namespace std::chrono;
		auto cur_time = system_clock::now();
		auto cur_epoch = duration_cast<seconds>(cur_time.time_since_epoch());
		return to_string(cur_epoch.count());
	}
};