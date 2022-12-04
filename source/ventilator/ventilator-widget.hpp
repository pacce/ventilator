#ifndef VENTILATION_VENTILATOR_WIDGET_HPP__
#define VENTILATION_VENTILATOR_WIDGET_HPP__

#include <cstdint>
#include <QFrame>
#include <QLabel>
#include <QWidget>
#include <ventilation/ventilation.hpp>

#include "spinbox/spinbox-peep.hpp"

namespace ventilator {
    class Ventilator : public QFrame {
        Q_OBJECT
        public:
            Ventilator(QWidget * parent = nullptr);
            ~Ventilator();
        signals:
            void peep(const ventilation::PEEP<double>& p) const;
        private:
            spinbox::PEEP * peep_;
    };
} // namespace ventilator

#endif // VENTILATION_VENTILATOR_WIDGET_HPP__
