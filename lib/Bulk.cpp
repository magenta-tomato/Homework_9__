#include "Bulk.h"


// цикл обработки команд
void Bulk::get( string cmd, vector<string>& res )
{
    // определяем очередной тип блока
    if (state == State::Unset) {

        if (cmd != "{") {
            state = staticBlock(cmd);
        }
        else{
            d_counter = 1;
            state = dynamicBlock(cmd);
        }
    }
    // продолжаем обрабатывать динамический блок
    else if (state == State::Dynamic) {
        state = dynamicBlock(cmd);
    }
    // продолжаем обрабатывать статический блок
    else if (state == State::Static) {
        state = staticBlock(cmd);
    }
}

void Bulk::end()
{
    // для статистического блока при конце ввода завершаем принудительно
    if (state == State::Static) {
        //writeFile();
    }
}

// очередной символ обрабатывается в рамках статического блока
State Bulk::staticBlock( string cmd )
{
    // завершаем принудительно по нахождению { - следующий блок : динамический 
    if (cmd == "{") {
        //writeFile();
        d_counter = 1;
        return State::Dynamic;
    }
    // } игнорируем
    else if (cmd == "}") {
        return State::Static;
    }

    // очередная команда
    commands.push_back(cmd);
    // первая команда
    if (commands.size()  == 1) {
        //setFileName();
    }
    // завершаем планово по нахождению всех N команд - какой будет следующий блок : неизвестно
    else if( commands.size() == sz) {
       // writeFile();
        return State::Unset;
    }
    return State::Static;
    
}

// очередной символ обрабатывается в рамках динамического блока
State Bulk::dynamicBlock( string cmd )
{
    // {
    if (cmd == "{") {
        d_counter++;
        return State::Dynamic;
    }
    // }
    else if (cmd == "}") {
        d_counter--;
        // завершеаем планово по нахождению нужного количества }
        if (d_counter == 0) {
            //writeFile();
            return State::Unset;
        }
        // продолжаем
        else {
            return State::Dynamic;
        }
    }

    // очередная команда
    commands.push_back(cmd);
    // первая команда
    if (commands.size() == 1) {
        //setFileName();
    }
    // продолжаем
    return State::Dynamic;
}