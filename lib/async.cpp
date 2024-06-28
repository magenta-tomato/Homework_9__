#include "async.h"


namespace async
{
    extern WriteThreads tObj;
    extern unordered_set<void*> contextArray;

    handle_t connect(std::size_t bulk)
    {
        Context* cont = new Context();
        contextArray.insert((void*)cont);
        return (void*)cont;
    }

    void receive(handle_t handle, const char* data, std::size_t size)
    {
        // передача данных в контекст
        vector<string> res;
        static_cast<Context*>(handle)->get(data, res);

        // если есть готовые данные - передача их в поток записи
        if (!res.empty()) {
            tObj.get(res);
        }
    }

    void disconnect(handle_t handle)
    {
        static_cast<Context*>(handle)->end();
        receive(handle, nullptr, 0);
        contextArray.erase(handle);
        if (contextArray.empty()) {
            tObj.noMoreDataAhead();
        }
    }

    void wait()
    {
        tObj.wait();
    }
}
