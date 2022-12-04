#include "pcv.hpp"
#include <QFormLayout>

namespace ventilator {
namespace pcv {
    PCV::PCV(QWidget * parent) : QWidget(parent) {
        peep_ = new spinbox::PEEP;
        peak_ = new spinbox::pressure::Peak;

        QFormLayout * form = new QFormLayout(this);
        form->addRow("Positive End-Expiratory Pressure (cmH<sub>2</sub>O)", peep_);
        form->addRow("Peak Pressure (cmH<sub>2</sub>O)", peak_);

        setLayout(form);
        connect(peep_, &spinbox::PEEP::peep, this, &PCV::peep);
        connect(peak_, &spinbox::pressure::Peak::pressure, this, &PCV::peak);
    }
    PCV::~PCV() {}
} // namesp:ace pcv
} // namespace ventilator
