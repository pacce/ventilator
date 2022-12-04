#include "lung-widget.hpp"

#include <QFormLayout>

namespace ventilator {
namespace lung {
    Lung::Lung(QWidget * parent)
        : QFrame(parent)
    {
        compliance_ = new spinbox::Compliance;
        resistance_ = new spinbox::Resistance;

        QFormLayout * layout = new QFormLayout;
        layout->addRow("Compliance (mL.cmH<sub>2</sub>O<sup>-1</sup>)", compliance_);
        layout->addRow("Resistance (cmH<sub>2</sub>O.s.L<sup>-1</sup>)", resistance_);
        setLayout(layout);

        connect(
                  compliance_
                , &spinbox::Compliance::compliance
                , this, [this](const ventilation::Compliance<double>& c) { emit compliance(c); }
                );
        connect(
                  resistance_
                , &spinbox::Resistance::resistance
                , this
                , [this](const ventilation::Resistance<double>& c) { emit resistance(c); }
                );
    }

    Lung::~Lung() {}
} // namespace lung
} // namespace ventilator
