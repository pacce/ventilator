#include "ventilator-vcv.hpp"
#include <QVBoxLayout>
#include <QFormLayout>

namespace ventilator {
namespace modes {
    VCV::VCV(QWidget * parent) : QWidget(parent) {
        label_  = new QLabel("Volume Controlled Ventilation");
        peep_   = new spinbox::PEEP;

        QFormLayout * form = new QFormLayout;
        form->addRow("Positive End-Expiratory Pressure (cmH<sub>2</sub>O)", peep_);

        QVBoxLayout * layout = new QVBoxLayout;
        layout->addWidget(label_);
        layout->addLayout(form);

        setLayout(layout);
        connect(peep_, &spinbox::PEEP::peep, this, &VCV::peep);
    }
    VCV::~VCV() {}
} // namesp:ace modes
} // namespace ventilator
