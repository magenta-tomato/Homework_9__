#pragma once

#include "Model.h"
#include "Shape.h"
#include <vector>
using namespace std;

class Model;

//---------------------------------------------------------------------------------
// обработка действий пользователя и обновление модели
class Controller
{
public:
	void setModel(Model* m);

	// создание нового документа 
	void createDoc();
	// импорт документа из файла
	void importDoc();
	// экспорт документа в файл
	void exportDoc();
	// создание графического примитива
	void createGraphic();
	// удаление графического примитива
	void removeGraphic();

private:

	Model* _m;
};