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
#include "lung.hpp"
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

        ventilator::lung::Lung * lung_;
        // ventilator::lung::Compliance * c_;
        // ventilator::lung::Resistance * r_;

        ventilator::Ventilator * v;
};

#endif // VENTILATIOR_WINDOW_HPP__
