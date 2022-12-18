#include "ventilator-widget.hpp"

#include <QVBoxLayout>

namespace ventilator {
    Ventilator::Ventilator(QWidget * parent)
        : QGroupBox(parent)
    {
        pcv_ = new ventilator::modes::PCV;
        vcv_ = new ventilator::modes::VCV;

        QRadioButton * radio1 = new QRadioButton("PCV");
        QRadioButton * radio2 = new QRadioButton("VCV");
        radio1->setChecked(true);

        QVBoxLayout * layout = new QVBoxLayout;
        layout->addWidget(radio1);
        layout->addWidget(radio2);
        layout->addWidget(pcv_);
        layout->addWidget(vcv_);
        layout->addStretch(1);
        setLayout(layout);
        setTitle("Ventilator");

        connect(pcv_, &ventilator::modes::PCV::peep, this, &Ventilator::peep);
        connect(pcv_, &ventilator::modes::PCV::peak, this, &Ventilator::peak);

        connect(vcv_, &ventilator::modes::VCV::peep, this, &Ventilator::peep);
        connect(radio1, &QAbstractButton::clicked, this, [this]() { emit mode(ventilation::modes::Names::PCV); });
        connect(radio2, &QAbstractButton::clicked, this, [this]() { emit mode(ventilation::modes::Names::VCV); });
    }

    Ventilator::~Ventilator() {}
} // namespace ventilator
