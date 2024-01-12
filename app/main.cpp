#include "lib.h"

#include <iostream>


IpFilter initFilter(bool& isSuc)
{
    //string outFileName = "output.tsv";
    IpFilter filt(false, "", true);

    string line;
    string filename = "ip_filter.tsv";
    ifstream myfile(filename);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            filt.add(line);
        }
        myfile.close();
        isSuc = true;
    }
    else {
        cout << "file not found " + filename << endl;
        isSuc = false;
    }
    return filt;
}



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