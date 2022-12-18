#ifndef VENTILATION_VENTILATOR_WIDGET_HPP__
#define VENTILATION_VENTILATOR_WIDGET_HPP__

#include <cstdint>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
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
            void vcv(const ventilator::setup::VCV<double>) const;
            void pcv(const ventilator::setup::PCV<double>) const;
        private:
            ventilator::modes::PCV *    pcv_;
            ventilator::modes::VCV *    vcv_;
    };
} // namespace ventilator

#endif // VENTILATION_VENTILATOR_WIDGET_HPP__
