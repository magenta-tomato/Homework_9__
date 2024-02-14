#include "View.h"


void View::setController(Controller* c) 
{ 
	_c = c; 
}

// передача действий пользователя контроллеру
void View::createDocClicked() 
{ 
	_c->createDoc();
}
	
void View::importDocClicked() 
{ 
	_c->importDoc(); 
}
	
void View::exportDocClicked() 
{ 
	_c->exportDoc(); 
}
	
void View::createGraphicClicked() 
{ 
	_c->createGraphic(); 
}
	
void View::removeGraphicClicked() 
{ 
	_c->removeGraphic(); 
}

// получение данных от модели и их отображение
void View::update(vector<Shape> v)
{
	int x = 0;
	int y = 0;
	int delta = 100;
	for (auto i : v) {
		i.draw(x, y);
		x += delta;
		y += delta;
	}
}
