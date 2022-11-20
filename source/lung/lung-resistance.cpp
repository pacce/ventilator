#include "lung-resistance.hpp"

#include <iostream>
#include <QVBoxLayout>

namespace ventilator {
namespace lung {
    Resistance::Resistance(QWidget * parent)
        : QWidget(parent)
    {
        values_     = new QDoubleSpinBox;
        validator_  = new QDoubleValidator(1.0, 100.0, 1, values_);
        values_->setRange(1.0, 100.0);

        QLabel * label = new QLabel("Resistance (cmH<sub>2</sub>O)");
        QVBoxLayout * layout = new QVBoxLayout;
        layout->addWidget(label);
        layout->addWidget(values_);

        this->setLayout(layout);
        connect(
                  values_
                , QOverload<double>::of(&QDoubleSpinBox::valueChanged)
                , this
                , &Resistance::update
                );
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
