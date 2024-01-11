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

// добавить новую строку
void IpFilter::add(string val)
{
    _vec.push_back(split(val, '.'));
}

// соединяем части строки с разделителем в 4-х байтное число
uint32_t IpFilter::split(const string& str, char d)
{   
    uint32_t r = 0;

    string::size_type start = 0;
    string::size_type stop = str.find_first_of(d);
    string subStr;
    uint32_t val;
    int counter = 3;
    while (stop != std::string::npos && counter > 0)
    {
        subStr = str.substr(start, stop - start);
        val = atoi(subStr.c_str());
        r |= (val << counter * 8);
        counter--;

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    subStr = str.substr(start);
    val = atoi(subStr.c_str());
    r |= (val << counter * 8);

    return r;
}

// сортировка в обратном лексикографическом порядке
void IpFilter::sorting()
{
    _resVec.clear();

    sort(_vec.begin(), _vec.end(), std::greater<uint32_t>() );
    for (auto i : _vec) {
        print( join(i, '.') );
    }
    
}

// соединяем байты 4-х байтного числа в строку с добавлением разделителя
string IpFilter::join( uint32_t v, char d )
{
    string res; 

    res += to_string( byteVal(v,1) );
    res += d;
    res += to_string( byteVal(v,2) );
    res += d;
    res += to_string( byteVal(v,3) );
    res += d;
    res += to_string( byteVal(v,4) );

    return res;
}

// фильтр по первому байту 
void IpFilter::filter(uint8_t n)
{
    _resVec.clear();
    for( auto i : _vec ){
        if( byteVal(i,1) == n) {
            print( join(i, '.') );
        }
    }
}

// фильтр по первому и второму байтам
void IpFilter::filter(int n, int m)
{
    _resVec.clear();
    for (auto i : _vec) {
        if( byteVal(i,1) == n && byteVal(i,2) == m) {
            print( join(i, '.') );
        }
    }
}

// фильтр - один из байт равен значению
void IpFilter::filter_any(int n)
{
    _resVec.clear();
    for (auto i : _vec) {
        if( byteVal(i,1) == n ||
            byteVal(i,2) == n ||
            byteVal(i,3) == n ||
            byteVal(i,4) == n ){
                print(join(i, '.'));
        }
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

uint8_t IpFilter::byteVal(uint32_t val, int ind)
{
    if (ind == 1) {
        return (val & 0xFF000000) >> 24;
    }
    if (ind == 2) {
        return (val & 0x00FF0000) >> 16;
    }
    if (ind == 3) {
        return (val & 0x0000FF00) >> 8;
    }
    if (ind == 4) {
        return (val & 0x000000FF);
    }
    return 0;
}