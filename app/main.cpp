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


    bool isSuc, res;
    IpFilter filt = initFilter(isSuc);
    if (isSuc) {
        filt.sorting();
        filt.filter_any(46);

        size_t sz = filt._resVec.size();
        res = (sz == 34) &&
            filt._resVec[0] == "186.204.34.46" &&
            filt._resVec[1] == "186.46.222.194" &&
            filt._resVec[2] == "185.46.87.231" &&
            filt._resVec[3] == "185.46.86.132" &&
            filt._resVec[4] == "185.46.86.131" &&
            filt._resVec[5] == "185.46.86.131" &&
            filt._resVec[6] == "185.46.86.22" &&
            filt._resVec[7] == "185.46.85.204" &&
            filt._resVec[8] == "185.46.85.78" &&
            filt._resVec[9] == "68.46.218.208" &&
            filt._resVec[10] == "46.251.197.23" &&
            filt._resVec[11] == "46.223.254.56" &&
            filt._resVec[12] == "46.223.254.56" &&
            filt._resVec[13] == "46.182.19.219" &&
            filt._resVec[14] == "46.161.63.66" &&
            filt._resVec[15] == "46.161.61.51" &&
            filt._resVec[16] == "46.161.60.92" &&
            filt._resVec[17] == "46.161.60.35" &&
            filt._resVec[18] == "46.161.58.202" &&
            filt._resVec[19] == "46.161.56.241" &&
            filt._resVec[20] == "46.161.56.203" &&
            filt._resVec[21] == "46.161.56.174" &&
            filt._resVec[22] == "46.161.56.106" &&
            filt._resVec[23] == "46.161.56.106" &&
            filt._resVec[24] == "46.101.163.119" &&
            filt._resVec[25] == "46.101.127.145" &&
            filt._resVec[26] == "46.70.225.39" &&
            filt._resVec[27] == "46.70.147.26" &&
            filt._resVec[28] == "46.70.113.73" &&
            filt._resVec[29] == "46.70.29.76" &&
            filt._resVec[30] == "46.55.46.98" &&
            filt._resVec[31] == "46.49.43.85" &&
            filt._resVec[32] == "39.46.86.85" &&
            filt._resVec[33] == "5.189.203.46";
    }
    else {
        res = false;
    }
















   //IpFilter filt;

   // string line;
   // vector<string> vec;
   // while (getline(cin, line)) {
   //     if (line.empty()) {
   //         break;
   //     }
   //     filt.add(line);
   // }

   // filt.sorting();
   // filt.filter(1);
   // filt.filter(46, 70);
   // filt.filter_any(46);
   
    return 0;
}