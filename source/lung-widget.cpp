#include "lung-widget.hpp"

#include <iostream>
#include <QVBoxLayout>

namespace ventilator {

Lung::Lung(QWidget * parent)
    : QFrame(parent)
{
    label_ = new QLabel("Compliance (cmH<sub>2</sub>O)");
    compliance_ = new Parameter;

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(label_);
    layout->addWidget(compliance_);

    this->setLayout(layout);
}

Lung::~Lung()
{}

} // namespace ventilator
