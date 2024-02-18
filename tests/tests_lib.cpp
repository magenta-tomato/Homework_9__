#define BOOST_TEST_MODULE test_version

#include "Matrix.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    BOOST_CHECK(version() > 0);
}

BOOST_AUTO_TEST_CASE(test1)
{

	// бесконечная матрица int заполнена значениями - 1
	Matrix<int, -1> matrix;

	matrix[0][0] = -1;
	assert(matrix.size() == 0); // все ячейки свободны
	auto a = matrix[0][0];
	BOOST_CHECK(a == -1);
	BOOST_CHECK(matrix.size() == 0);
	matrix[100][100] = 314;
	BOOST_CHECK(matrix[100][100] == 314);
	BOOST_CHECK(matrix.size() == 1);
	// выведется одна строка
	// 100100314
	string str;
	for (auto i : matrix) {
		int x;
		int y;
		int v;
		//tie(x, y, v) = i;
		//cout << i;

		x = i.first.first;
		y = i.first.second;
		v = i.second;
		//cout << x << y << v << endl;
		str += x;
		str += y;
		str += v;
	}
	BOOST_CHECK( str.compare("100100314") == 0 );
	
}

BOOST_AUTO_TEST_SUITE_END()