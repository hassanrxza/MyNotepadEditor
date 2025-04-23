
#include <QApplication>

#include <MainWindow.hpp>

#include <QCoreApplication>
#include <QTextStream>

int main(int argc, char** argv)
{
    // Creating application
    QApplication a(argc, argv);

    // Creating main window
    MainWindow w;
    w.show();
    w.setWindowTitle("My Notepad Editor");

    return QApplication::exec();
}
