#pragma once

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

enum class State {
    Unset,
    Static,
    Dynamic
};

class Bulk
{
public:

    Bulk(int _sz=0) : sz(_sz)  {}

    void get( string cmd, vector<string>& res );
    void end();
    State staticBlock(string cmd);
    State dynamicBlock(string cmd);

private:
    State state = State::Unset;
    vector<string> commands;
    int sz;
    int d_counter = 0;
};