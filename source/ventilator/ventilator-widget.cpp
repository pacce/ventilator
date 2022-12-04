#include "ventilator-widget.hpp"

#include <QVBoxLayout>

namespace ventilator {
    Ventilator::Ventilator(QWidget * parent)
        : QGroupBox(parent)
    {
        pcv_ = new ventilator::pcv::PCV;

        QVBoxLayout * layout = new QVBoxLayout;
        layout->addWidget(pcv_);
        setLayout(layout);
        setTitle("Ventilator");

        connect(pcv_, &ventilator::pcv::PCV::peep, this, &Ventilator::peep);
        connect(pcv_, &ventilator::pcv::PCV::peak, this, &Ventilator::peak);
    }

    Ventilator::~Ventilator() {}
} // namespace ventilator
