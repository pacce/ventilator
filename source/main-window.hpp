#ifndef VENTILATIOR_WINDOW_HPP__
#define VENTILATIOR_WINDOW_HPP__

#include <cstdint>
#include <QChart>
#include <QLineSeries>
#include <QMainWindow>
#include <QPointF>
#include <QVector>

#include <ventilation/ventilation.hpp>

#include "chart.hpp"
#include "parameter.hpp"
#include "ventilator.hpp"

class Ventilator : public QMainWindow {
    Q_OBJECT
    public:
        Ventilator(QWidget * parent = 0);
        ~Ventilator();
    private:
        ventilator::Chart * flow_;
        ventilator::Chart * pressure_;
        ventilator::Chart * volume_;
        ventilator::Parameter * compliance_;

        ventilator::Ventilator * v;
};

#endif // VENTILATIOR_WINDOW_HPP__
