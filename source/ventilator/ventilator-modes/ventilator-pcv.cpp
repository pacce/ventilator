#include "ventilator-pcv.hpp"
#include <QVBoxLayout>
#include <QFormLayout>

namespace ventilator {
namespace modes {
    PCV::PCV(QWidget * parent) : QWidget(parent) {
        label_  = new QLabel("Pressure Controlled Ventilation");
        peep_   = new spinbox::PEEP;
        peak_   = new spinbox::pressure::Peak;

        QFormLayout * form = new QFormLayout;
        form->addRow("Positive End-Expiratory Pressure (cmH<sub>2</sub>O)", peep_);
        form->addRow("Peak Pressure (cmH<sub>2</sub>O)", peak_);

        QVBoxLayout * layout = new QVBoxLayout;
        layout->addWidget(label_);
        layout->addLayout(form);

        setLayout(layout);
        connect(peep_, &spinbox::PEEP::peep, this, &PCV::peep);
        connect(peak_, &spinbox::pressure::Peak::pressure, this, &PCV::peak);
    }
    PCV::~PCV() {}
} // namesp:ace modes
} // namespace ventilator
