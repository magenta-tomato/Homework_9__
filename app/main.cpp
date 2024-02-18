#include <iostream>
#include <cassert>
#include <tuple>

#include "Matrix.h"

void test()
{
	Matrix<int, -1> matrix;

	matrix[0][0] = -1;
	assert(matrix.size() == 0); // все ячейки свободны
	auto a = matrix[0][0];
	assert(a == -1);
	assert(matrix.size() == 0);
	matrix[100][100] = 314;
	assert(matrix[100][100] == 314);
	assert(matrix.size() == 1);
	// выведется одна строка
	// 100100314
	for (auto i : matrix) {
		int x;
		int y;
		int v;
		//tie(x, y, v) = i;
		//cout << i;

		x = i.first.first;
		y = i.first.second;
		v = i.second;
		cout << x << y << v << endl;
	}
}

int main()
{
	test();

	Matrix<int, 0> matrix;

	// главная диагональ
	for (int x = 0, y = 0; x <= 9 && y <= 9; x++, y++) {
		matrix[x][y] = x;
	}
	// второстепенная диагональ
	for (int x = 9, y = 0; x >= 0 && y <= 9; x--, y++) {
		matrix[x][y] = x;
	}

	// выводим фрагмент матрицы от [1,1] до [8,8]
	for (int x = 1; x <= 8; x++) {
		for (int y = 1; y <= 8; y++) {
			int val = matrix.value(x, y);
			cout << val << " ";
		}
		cout << endl;
	}

	// количество занятых ячеек
	cout << matrix.size() << endl;

	// занятые ячейки с позициями
	for (auto i : matrix) {
		int x = i.first.first;
		int y = i.first.second;
		int v = i.second;
		cout << x << "," <<  y << ":" << v << endl;
	}
}