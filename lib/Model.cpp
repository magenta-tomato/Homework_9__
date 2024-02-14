#include "version.h"

int version() {
    return PROJECT_VERSION_PATCH;
}


#include "Model.h"

// обнулить данные
void Model::reset()
{
	_shapes.clear();
	_v->update(_shapes);
}

// инициализировать данные 
void Model::init(vector<Shape> v)
{
	_shapes = v;
	_v->update(_shapes);
}

// добавить в массив новую фигуру
void Model::add(Shape x)
{
	_shapes.push_back(x);
	_v->update(_shapes);
}

// удалить из массива фигуру
void Model::remove(int shapeIndex)
{
	_shapes.erase(_shapes.begin() + shapeIndex);
	_v->update(_shapes);
}
