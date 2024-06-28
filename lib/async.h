#pragma once


#include "Bulk.h"
#include "WriteThreads.h"
#include "Context.h"
#include <unordered_set>
using namespace std;


/*
start - создаем новый объект Context
Заносим его в список контекстов
get - передаем данные парсеру Bulk конкретного контекста
В ответ можем получить данные, которые можно записать на выход
Эти данные передаются единственному объекту WriteThreads, 
занимающемуся многопточной записью
Lib::end - сообщаем парсеру Bulk что данных больше не предвидется,
получаем от парсера последнюю порцию данных
*/


namespace async 
{

using handle_t = void *;

extern WriteThreads tObj;
extern unordered_set<void*> contextArray;

handle_t connect(std::size_t bulk);


void receive(handle_t handle, const char* data, std::size_t size);

void disconnect(handle_t handle);

void wait();

}
