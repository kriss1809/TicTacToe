#include <QtWidgets/QApplication>
#include "teste.h"
#include "MyGUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    testAll();

    Repo repo{ "jocuri.txt" };
    Service srv{ repo };
    MyGUI gui{ srv };
    gui.show();
    
    return a.exec();
}
