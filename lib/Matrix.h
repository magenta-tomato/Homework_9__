#pragma once

#include <map>
using namespace std;

int version();

template <typename T, int default_value>
class Matrix
{
private:
	int sz;

	//---------------------------------------------------------------------------
	class Cell
	{
	public:
		// ctor
		Cell(Matrix* _m, int _row) :m(_m), row(_row), val(default_value) {}

		// []
		Cell& operator[](int i) {
			col = i;
			return *this;
		}
		// =
		void operator=(int _val) {
			val = _val;
			// удаляем из списка
			if (_val == default_value) {
				m->cells.erase(make_pair(row, col));
			}
			// обновляем/добавляем в значение в список
			else {
				m->cells[make_pair(row, col)] = _val;
			}
		}
		// ==
		bool operator==(int _val) {
			auto it = m->cells.find(make_pair(row, col));

			// сравниваем c реальным значение, оно есть в списке и соответствует
			if (_val != default_value) {
				return (it != m->cells.end() && _val == it->second);
			}
			// сравниваем с default_value, такого значения в списке быть не должно
			return (it == m->cells.end());

		}
	private:
		int row;
		int col;
		int val;
		Matrix* m;
	};
	//-------------------------------------------------------------------------

public:
	// получение значения элемента
	int value(int row, int col)
	{
		auto it = cells.find(make_pair(row, col));
		if (it == cells.end())
			return default_value;

		return it->second;
	}

	// размер
	int size() {
		return cells.size();
	}

	//[]
	Cell operator[](int i) {
		return Cell(this, i);
	}

	// для цикла for по диапазону 
	auto begin() { return cells.begin(); }
	auto end() { return cells.end(); }

	map<pair<int, int>, int> cells;
};