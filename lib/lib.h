#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdint>
using namespace std;



int version();

class IpFilter
{
public:
	IpFilter(bool outConsole = true, string outFName = "", bool outVec = false);
	
	// добавить новую строку
	void add(string val);

	// сортировка в обратном лексикографическом порядке
	void sorting();

	// фильтр по первому байту 
	void filter(uint8_t n); 

	// фильтр по первому и второму байтам
	void filter(int n, int m);

	// фильтр - один из байт равен значению
	void filter_any(int n);

	vector<string> _resVec;
private:
	 
	vector<uint32_t> _vec;

	// соединяем части строки с разделителем в 4-х байтное число
	uint32_t split(const string& str, char d);
	// соединяем байты 4-х байтного числа в строку с добавлением разделителя
	string join(uint32_t v, char d );

	uint8_t byteVal(uint32_t val, int ind);

	// вывод в cout или файл
	void print( string s );
	string _outFName;
	ofstream _outfile;
	bool _outVec;
	bool _outConsole;

};
