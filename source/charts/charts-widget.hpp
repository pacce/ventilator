#ifndef VENTILATION_CHARTS_WIDGET_HPP__
#define VENTILATION_CHARTS_WIDGET_HPP__

#include <cstdint>
#include <QFrame>
#include <QLabel>
#include <QWidget>

#include "chart.hpp"

namespace ventilator {
namespace charts {
    class Charts : public QFrame {
        Q_OBJECT
        public:
            Charts(QWidget * parent = nullptr);
            ~Charts();
        public slots:
            void update(const ventilation::Packet<double>& p);
        private:
            Chart * flow_;
            Chart * pressure_;
            Chart * volume_;
    };
} // namespace charts
} // namespace ventilator

#endif // VENTILATION_CHARTS_WIDGET_HPP__
