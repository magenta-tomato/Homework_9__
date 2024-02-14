#include "Controller.h"

void Controller::setModel(Model* m)
{
	_m = m;
}

// создание нового документа 
void Controller::createDoc()
{
	// обнуление данных
	_m->reset();
}

// импорт документа из файла
void Controller::importDoc()
{
	vector<Shape> shapes;
	// open file
	// shapes = read fdata from file
	// инициализация массива фигур содержимым файла
	_m->init(shapes);
}

// экспорт документа в файл
void Controller::exportDoc()
{
	// получение текущих данных из модели и запись их в файл
	vector<Shape> shapes = _m->data();
	// open file
	// write shapes data to file
}

// создание графического примитива
void Controller::createGraphic()
{
	// добавление примитива в массив в модели
	Square x;
	_m->add(x);
	Circle y;
	_m->add(y);
}

// удаление графического примитива
void Controller::removeGraphic()
{
	// удаление примитива из массива модели
	int index = 1;
	_m->remove(index);
}
