#include <QApplication>
#include "main-window.hpp"

int
main(int argc, char** argv) {
    QApplication app(argc, argv);

    Ventilator window;
    window.show();

    return app.exec();
}
