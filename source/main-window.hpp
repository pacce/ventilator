#ifndef VENTILATIOR_WINDOW_HPP__
#define VENTILATIOR_WINDOW_HPP__

#include <cstdint>
#include <QChart>
#include <QLineSeries>
#include <QMainWindow>
#include <QPointF>
#include <QVector>

#include <ventilation/ventilation.hpp>

#include "charts.hpp"
#include "side-bar.hpp"

class Ventilator : public QMainWindow {
    Q_OBJECT
    public:
        Ventilator(QWidget * parent = 0);
        ~Ventilator();
    private:
        ventilator::charts::Charts * charts_;

        ventilator::Engine *           engine_;
        ventilator::sidebar::SideBar * side_bar_;
};

#endif // VENTILATIOR_WINDOW_HPP__
