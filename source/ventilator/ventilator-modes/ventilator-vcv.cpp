#include "ventilator-vcv.hpp"

#include <QAbstractAnimation>
#include <QFormLayout>
#include <QVBoxLayout>

namespace ventilator {
namespace modes {
    VCV::VCV(QWidget * parent) 
        : QScrollArea(parent)
        , is_expanded_(true)
    {
        setContentsMargins(0, 0, 0, 0);
        setMinimumHeight(0);

        label_  = new QLabel("Volume Controlled Ventilation");
        peep_   = new spinbox::PEEP;

        QFormLayout * form = new QFormLayout;
        form->addRow("Positive End-Expiratory Pressure (cmH<sub>2</sub>O)", peep_);

        QVBoxLayout * layout = new QVBoxLayout;
        layout->addWidget(label_);
        layout->addLayout(form);

        setLayout(layout);
        connect(peep_, &spinbox::PEEP::peep, this, &VCV::peep);

        animation_ = new QPropertyAnimation(this, "maximumHeight");
        animation_->setStartValue(0);
        animation_->setEndValue(layout->sizeHint().height());
        animation_->setDuration(200);

        collapse();
    }

    VCV::~VCV() {}

    void
    VCV::collapse() {
        animation_->setDirection(QAbstractAnimation::Backward);
        if (is_expanded_) {
            is_expanded_ = false;
            animation_->start();
        }
    }

    void
    VCV::expand() {
        animation_->setDirection(QAbstractAnimation::Forward);
        if (!is_expanded_) {
            is_expanded_ = true;
            animation_->start();
        }
    }
} // namesp:ace modes
} // namespace ventilator
