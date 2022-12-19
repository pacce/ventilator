#include "spinbox-peep.hpp"

namespace ventilator {
namespace spinbox {
    PEEP::PEEP(QWidget * parent)
        : QDoubleSpinBox(parent)
        , validator_(new QDoubleValidator(0.0, 20.0, 1, this))
    {
        setRange(0.0, 20.0);
        connect(this, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &PEEP::update);
    }

    PEEP::PEEP(const ventilation::PEEP<double>& p, QWidget * parent)
        : QDoubleSpinBox(parent)
        , validator_(new QDoubleValidator(0.0, 20.0, 1, this))
    {
        setValue(static_cast<double>(p));

        setRange(0.0, 20.0);
        connect(this, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &PEEP::update);
    }

    PEEP::~PEEP() {}

    ventilation::PEEP<double>
    PEEP::get() const {
        try {
            return ventilation::PEEP<double>(this->value());
        } catch (const std::exception& e) {
            return ventilation::PEEP<double>();
        }
    }

    void
    PEEP::update(double value) {
        try {
            ventilation::PEEP c(value);
            emit peep(c);
        } catch (const std::exception& e) {
        }
    }
} // namespace spinbox
} // namespace ventilator
