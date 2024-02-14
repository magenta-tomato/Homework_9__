#include "Model.h"
#include "View.h"
#include "Controller.h"

int main()
{
    Model m;
    View v;
    Controller c;
	
    v.setController(&c);
    c.setModel(&m);
    m.setView(&v);

    // действия пользователя
    v.createDocClicked(); 
    v.importDocClicked(); 
    v.exportDocClicked();
    v.createGraphicClicked(); 
    v.removeGraphicClicked();
}