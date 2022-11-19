#include "parameter.hpp"

namespace ventilator {
    Parameter::Parameter(QWidget * parent)
        : QDoubleSpinBox(parent)
        , validator_(new QDoubleValidator(0.0, 100.0, 1, this))
    {
        setRange(0.0, 100.0);
    }

    Parameter::~Parameter() {}
} // namespace ventilator
