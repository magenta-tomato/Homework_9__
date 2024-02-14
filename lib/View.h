#pragma once

#include "Controller.h"
#include "Shape.h"
#include <vector>
using namespace std;

class Controller;

//---------------------------------------------------------------------------------
// передача действий пользователя контроллеру
// получение данных от модели и их отображение
class View
{
public:
	void setController(Controller* c);

	// передача действий пользователя контроллеру
	void createDocClicked();
	void importDocClicked();
	void exportDocClicked();
	void createGraphicClicked();
	void removeGraphicClicked();

	// получение данных от модели и их отображение
	void update(vector<Shape> v);

private:
	Controller* _c;
};