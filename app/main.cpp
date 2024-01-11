#include "lib.h"

#include <iostream>

int main(int, char**) 
{
   IpFilter filt;

    string line;
    vector<string> vec;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }
        filt.add(line);
    }

    filt.sorting();
    filt.filter(1);
    filt.filter(46, 70);
    filt.filter_any(46);

    return 0;
}