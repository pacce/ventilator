#include "spinbox-compliance.hpp"

#include <QVBoxLayout>

namespace ventilator {
namespace spinbox {
    Compliance::Compliance(QWidget * parent)
        : QDoubleSpinBox(parent)
        , validator_(new QDoubleValidator(1.0, 100.0, 1, this))
    {
        setRange(1.0, 100.0);
        connect(this, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Compliance::update);
    }

    Compliance::Compliance(const ventilation::Compliance<double>& c, QWidget * parent)
        : QDoubleSpinBox(parent)
        , validator_(new QDoubleValidator(1.0, 100.0, 1, this))
    {
        setValue(static_cast<double>(c));

        setRange(1.0, 100.0);
        connect(this, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Compliance::update);
    }

    Compliance::~Compliance() {}

    void
    Compliance::update(double value) {
        try {
            ventilation::Compliance c(value * 1e-3);
            emit(compliance(c));
        } catch (const std::exception& e) {
        }
    }
} // namespace spinbox
} // namespace ventilator
