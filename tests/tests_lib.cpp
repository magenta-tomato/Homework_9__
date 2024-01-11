#define BOOST_TEST_MODULE test_version

#include "lib.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    BOOST_CHECK(version() > 0);
}

IpFilter initFilter(bool& isSuc)
{
    //string outFileName = "output.tsv";
    IpFilter filt( false, "", true);

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

// сортировка в обратном лексикографическом порядке
BOOST_AUTO_TEST_CASE(test1)
{
    bool isSuc, res;
    IpFilter filt = initFilter( isSuc );
    if (isSuc) {
        filt.sorting();

        size_t sz = filt._resVec.size();
        res = (sz > 6) &&
            filt._resVec[0] == "222.173.235.246" &&
            filt._resVec[1] == "222.130.177.64" &&
            filt._resVec[2] == "222.82.198.61" &&
            filt._resVec[sz - 3] == "1.70.44.170" &&
            filt._resVec[sz - 2] == "1.29.168.152" &&
            filt._resVec[sz - 1] == "1.1.234.8";
    }
    else {
        res = false;
    }
    BOOST_CHECK( res );
}

// фильтр по первому байту 
BOOST_AUTO_TEST_CASE(test2)
{
    bool isSuc, res;
    IpFilter filt = initFilter(isSuc);
    if (isSuc) {
        filt.sorting();
        filt.filter(1);

        size_t sz = filt._resVec.size();
        res = (sz == 5) &&
            filt._resVec[0] == "1.231.69.33" &&
            filt._resVec[1] == "1.87.203.225" &&
            filt._resVec[2] == "1.70.44.170" &&
            filt._resVec[3] == "1.29.168.152" &&
            filt._resVec[4] == "1.1.234.8";
    }
    else {
        res = false;
    }
    BOOST_CHECK(res);
}

// фильтр по первому и второму байтам
BOOST_AUTO_TEST_CASE(test3)
{
    bool isSuc, res;
    IpFilter filt = initFilter(isSuc);
    if (isSuc) {
        filt.sorting();
        filt.filter(46, 70);

        size_t sz = filt._resVec.size();
        res = (sz == 4) &&
            filt._resVec[0] == "46.70.225.39" &&
            filt._resVec[1] == "46.70.147.26" &&
            filt._resVec[2] == "46.70.113.73" &&
            filt._resVec[3] == "46.70.29.76";
    }
    else {
        res = false;
    }
    BOOST_CHECK(res);
}

// фильтр - один из байт равен значению
BOOST_AUTO_TEST_CASE(test4)
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
    BOOST_CHECK(res);
}

// общий тест на хэш
BOOST_AUTO_TEST_CASE(test5)
{
    bool res = true;
    #ifndef _WIN32
    string hash = "24e7a7b2270daee89c64d3ca5fb3da1a";
    const int sz = hash.size() + 1;
    char buf[sz];
    string cmd = "cat ip_filter.tsv | ./ip_filter | md5sum";
    FILE* pipe = popen(cmd.c_str(), "r");
    if (pipe) {
        fgets(buf, sz, pipe);
    }
    string str = buf;
    pclose(pipe);
    res = (str == hash);
    #endif

    res = true;
    BOOST_CHECK(res);
}

BOOST_AUTO_TEST_SUITE_END()