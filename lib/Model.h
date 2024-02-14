#pragma once

int version();

#include "View.h"
#include "Shape.h"
#include <vector>
using namespace std;

class View;

//---------------------------------------------------------------------------------
// получение данных от контроллера, выполнение операций на данными, передача их в View
// данные представляют собой массив фигур Shape
class Model
{
public:
	void setView(View* v){ _v = v; }

	// обнулить данные
	void reset();
	
	// инициализировать данные 
	void init(vector<Shape> v);
	
	// добавить в массив новую фигуру
	void add(Shape x);
	
	// удалить из массива фигуру
	void remove(int shapeIndex);
	
	// получить массив фигур 
	vector<Shape> data(){ return _shapes; }
private:
	vector<Shape> _shapes;
	View* _v;
};