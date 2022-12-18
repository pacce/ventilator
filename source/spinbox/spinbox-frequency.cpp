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

    ventilation::frequency::Frequency<double>
    Frequency::get() const {
        try {
            return ventilation::frequency::Frequency<double>(this->value() / 60.0);
        } catch (const std::exception& e) {
            return ventilation::frequency::Frequency<double>(1.0);
        }
    }

    void
    Frequency::update(int) { emit frequency(this->get()); }
} // namespace spinbox
} // namespace ventilator
