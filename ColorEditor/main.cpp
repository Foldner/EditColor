#include "editcolor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EditColor w;
    w.setFixedSize(300, 200);
    w.setWindowIcon(QIcon(":/icons/winIcon.ico"));
    w.show();
    return a.exec();
}
