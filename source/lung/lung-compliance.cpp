#include "lung-compliance.hpp"

#include <iostream>
#include <QVBoxLayout>

namespace ventilator {
namespace lung {
    Compliance::Compliance(QWidget * parent)
        : QDoubleSpinBox(parent)
        , validator_(new QDoubleValidator(1.0, 100.0, 1, this))
    {
        setRange(1.0, 100.0);
        connect(this, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Compliance::update);
    }

    Compliance::~Compliance() {}

    void
    Compliance::update(double value) {
        try {
            ventilation::Compliance c(value);
            emit(compliance(c));
        } catch (const std::exception& e) {
        }
    }
} // namespace lung
} // namespace ventilator
