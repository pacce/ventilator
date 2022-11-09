#ifndef VENTILATOR_WIDGET_HPP__
#define VENTILATOR_WIDGET_HPP__

#include <chrono>
#include <QWidget>
#include <ventilation/ventilation.hpp>

namespace ventilator {
    class Ventilator : public QWidget {
        Q_OBJECT
        public:
            Ventilator(QWidget * parent = 0);
            ~Ventilator();
        signals:
            void
            pressure(ventilation::Pressure<double> p);
        public slots:
            void
            step();
        private:
            std::chrono::duration<double>   step_;

            ventilation::Lung<double>           lung_;
            ventilation::cycle::Cycle<double>   cycle_;
            ventilation::modes::PCV<double>     ventilator_;

    };
} // namespace ventilator

#endif // VENTILATOR_WIDGET_HPP__
