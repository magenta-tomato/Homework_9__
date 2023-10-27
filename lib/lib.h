#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
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
	void filter(int n);

	// фильтр по первому и второму байтам
	void filter(int n, int m);

	// фильтр - один из байт равен значению
	void filter_any(int n);

	vector<string> _resVec;
private:

	vector<vector<int>> _vec;

	// разделить/соединить строку на массив чисел через разделитель
	vector<int> split(const string& str, char d);
	string join(vector<int>& vec, char d, bool useDelimiter = true);

	// вывод в cout или файл
	void print( string s );
	string _outFName;
	ofstream _outfile;
	bool _outVec;
	bool _outConsole;

};
