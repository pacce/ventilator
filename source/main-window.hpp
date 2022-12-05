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
#include "lung.hpp"
#include "sidebar.hpp"
#include "spinbox.hpp"
#include "ventilator.hpp"

class Ventilator : public QMainWindow {
    Q_OBJECT
    public:
        Ventilator(QWidget * parent = 0);
        ~Ventilator();
    private:
        ventilator::charts::Charts * charts_;

        ventilator::Engine *           engine_;
        ventilator::sidebar::Sidebar * sidebar_;
};

#endif // VENTILATIOR_WINDOW_HPP__
