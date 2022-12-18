#include "spinbox-pressure-peak.hpp"

namespace ventilator {
namespace spinbox {
namespace pressure {
    Peak::Peak(QWidget * parent)
        : QDoubleSpinBox(parent)
        , validator_(new QDoubleValidator(0.0, 20.0, 1, this))
    {
        setRange(0.0, 20.0);
        connect(this, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Peak::update);
    }

    Peak::~Peak() {}
    
    ventilation::pressure::Peak<double>
    Peak::get() const {
        try {
            return ventilation::pressure::Peak<double>(this->value());
        } catch (const std::exception& e) {
            return ventilation::pressure::Peak<double>();
        }
    }

    void
    Peak::update(double value) {
        try {
            ventilation::pressure::Peak c(value);
            emit pressure(c);
        } catch (const std::exception& e) {
        }
    }
} // namespace pressure
} // namespace spinbox
} // namespace ventilator
