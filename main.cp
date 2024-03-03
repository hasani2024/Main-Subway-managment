



#include "mainwindow.h"
#include "subwaymanagement.h"
#include <QApplication>

void Menu(){


}


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    Menu();
    MainWindow *m = new MainWindow();
    m->show();



    return a.exec();
}







