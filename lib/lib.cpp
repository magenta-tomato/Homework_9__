#include "lib.h"

#include "version.h"

int version() {
    return PROJECT_VERSION_PATCH;
}


IpFilter::IpFilter(bool outConsole, string outFName, bool outVec)
{
    _outFName = outFName;
    if (!outFName.empty()) {
        _outfile.open(outFName);
    }
    _outConsole = outConsole;
    _outVec = outVec;
}

// разделяем строку на массив чисел через разделитель
vector<int> IpFilter::split(const string& str, char d)
{
    vector<int> r;

    string::size_type start = 0;
    string::size_type stop = str.find_first_of(d);
    string subStr;
    while (stop != std::string::npos)
    {
        subStr = str.substr(start, stop - start);
        r.push_back(atoi(subStr.c_str()));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    subStr = str.substr(start);
    r.push_back(atoi(subStr.c_str()));

    return r;
}

// соединяем массив чисел в строку через разделитель
string IpFilter::join(vector<int>& v, char d, bool useDelimiter)
{
    string res;
    for (int i = 0; i < v.size(); i++) {
        res += to_string(v[i]);
        if (useDelimiter && i < v.size() - 1) {
            res += d;
        }
    }
    return res;
}

// добавить новую строку
void IpFilter::add(string val)
{
    _vec.push_back( split(val,'.') );
}

// фильтр по первому байту 
void IpFilter::filter(int n)
{
    _resVec.clear();
    for (auto i : _vec) {
        if (i[0] == n ){
            print(join(i, '.'));
        }
    }
}

// фильтр по первому и второму байтам
void IpFilter::filter(int n, int m)
{
    _resVec.clear();
    for (auto i : _vec) {
        if (i[0] == n && i[1] == m ){
            print(join(i, '.'));
        }
    }
}

// фильтр - один из байт равен значению
void IpFilter::filter_any(int n)
{
    _resVec.clear();
    for (auto i : _vec) {
        for (auto j : i) {
            if (j == n) {
                print(join(i, '.'));
                break;
            }
        }
    }
}

// сортировка в обратном лексикографическом порядке
void IpFilter::sorting()
{
    _resVec.clear();

    auto comparator = [](vector<int>& a, vector<int>& b) {
        //return ( stoll(join(a, ' ', false)) > stoll(join(b, ' ', false)) );
        for (int i = 0; i < a.size() && i < b.size(); i++) {
            if (a[i] > b[i]) {
                return true;
            }
            else if (a[i] < b[i]) {
                return false;
            }
        }
        return false;
    };

    sort(_vec.begin(), _vec.end(), comparator);
    for (auto i : _vec) {
        print(join(i, '.'));
    }
}

// вывод в cout или файл
void IpFilter::print(string s)
{
    if(!_outFName.empty() ){
        _outfile << s << endl;
    }
    if( _outConsole ){
        cout << s << endl;
    }
    if (_outVec) {
        _resVec.push_back(s);
    }
}