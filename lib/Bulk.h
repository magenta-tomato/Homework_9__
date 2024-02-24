#pragma once

#include <iostream>
#include <cctype>
#include <string>
#include <chrono>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int version();

enum class State {
    Unset,
    Static,
    Dynamic
};

class Bulk
{
public:

    Bulk(int _sz) : sz(_sz)  {}
    void processLoop();
    vector<string> testRes;

    State staticBlock(string cmd);
    State dynamicBlock(string cmd);

private:
    void setFileName();
    void writeFile();
    string getTime();

    vector<string> commands;
    fstream file;
    int sz;

    int d_counter;
    string fileName;

};