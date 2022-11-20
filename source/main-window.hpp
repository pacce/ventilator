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
#include "ventilator.hpp"

class Ventilator : public QMainWindow {
    Q_OBJECT
    public:
        Ventilator(QWidget * parent = 0);
        ~Ventilator();
    private:
        ventilator::charts::Charts * charts_;

        ventilator::lung::Lung *    lung_;
        ventilator::Engine *        engine_;

        ventilator::PEEP *  peep_;
};

#endif // VENTILATIOR_WINDOW_HPP__
