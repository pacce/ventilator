#include "lung-resistance.hpp"

#include <QVBoxLayout>

namespace ventilator {
namespace lung {
    Resistance::Resistance(QWidget * parent)
        : QDoubleSpinBox(parent)
        , validator_(new QDoubleValidator(1.0, 100.0, 1, this))
    {
        setRange(1.0, 100.0);
        connect(this, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Resistance::update);
    }

    Resistance::~Resistance() {}

    void
    Resistance::update(double value) {
        try {
            ventilation::Resistance r(value);
            emit(resistance(r));
        } catch (const std::exception& e) {
        }
    }
} // namespace lung
} // namespace ventilator
