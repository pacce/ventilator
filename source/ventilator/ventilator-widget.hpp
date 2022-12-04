#ifndef VENTILATION_VENTILATOR_WIDGET_HPP__
#define VENTILATION_VENTILATOR_WIDGET_HPP__

#include <cstdint>
#include <QGroupBox>
#include <QLabel>
#include <QWidget>
#include <ventilation/ventilation.hpp>

#include "ventilator-modes/ventilator-modes.hpp"
#include "spinbox/spinbox-peep.hpp"

namespace ventilator {
    class Ventilator : public QGroupBox {
        Q_OBJECT
        public:
            Ventilator(QWidget * parent = nullptr);
            ~Ventilator();
        signals:
            void peak(const ventilation::pressure::Peak<double>& p) const;
            void peep(const ventilation::PEEP<double>& p) const;
        private:
            ventilator::modes::PCV *  pcv_;
    };
} // namespace ventilator

#endif // VENTILATION_VENTILATOR_WIDGET_HPP__
