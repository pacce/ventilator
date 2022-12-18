#include "spinbox-frequency.hpp"

#include <QVBoxLayout>

namespace ventilator {
namespace spinbox {
    Frequency::Frequency(QWidget * parent)
        : QSpinBox(parent)
        , validator_(new QIntValidator(1, 100, this))
    {
        setRange(1, 100);
        connect(this, QOverload<int>::of(&QSpinBox::valueChanged), this, &Frequency::update);
    }

    Frequency::~Frequency() {}

    void
    Frequency::update(int value) {
        try {
            double v = static_cast<double>(value) / 60.0;
            ventilation::frequency::Frequency f(v);
            emit frequency(f);
        } catch (const std::exception& e) {
        }
    }
} // namespace spinbox
} // namespace ventilator
