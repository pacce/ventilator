#include "lung-widget.hpp"

#include <iostream>
#include <QFormLayout>

namespace ventilator {
namespace lung {
    Lung::Lung(QWidget * parent)
        : QFrame(parent)
    {
        compliance_ = new Compliance;
        resistance_ = new Resistance;

        QFormLayout * layout = new QFormLayout;
        layout->addRow("Compliance (cmH<sub>2</sub>O)", compliance_);
        layout->addRow("Resistance (cmH<sub>2</sub>O)", resistance_);
        setLayout(layout);

        connect(compliance_, &Compliance::compliance, this, [this](const ventilation::Compliance<double>& c) { emit compliance(c); });
        connect(resistance_, &Resistance::resistance, this, [this](const ventilation::Resistance<double>& c) { emit resistance(c); });
    }

    Lung::~Lung() {}
} // namespace lung
} // namespace ventilator
