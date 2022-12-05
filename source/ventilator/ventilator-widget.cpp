#include "ventilator-widget.hpp"

#include <QVBoxLayout>

namespace ventilator {
    Ventilator::Ventilator(QWidget * parent)
        : QGroupBox(parent)
    {
        pcv_ = new ventilator::modes::PCV;
        vcv_ = new ventilator::modes::VCV;

        QVBoxLayout * layout = new QVBoxLayout;
        layout->addWidget(pcv_);
        layout->addWidget(vcv_);
        setLayout(layout);
        setTitle("Ventilator");

        connect(pcv_, &ventilator::modes::PCV::peep, this, &Ventilator::peep);
        connect(pcv_, &ventilator::modes::PCV::peak, this, &Ventilator::peak);

        connect(vcv_, &ventilator::modes::VCV::peep, this, &Ventilator::peep);
    }

    Ventilator::~Ventilator() {}
} // namespace ventilator
