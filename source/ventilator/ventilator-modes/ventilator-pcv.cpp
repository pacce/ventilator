#include "ventilator-pcv.hpp"

#include <QAbstractAnimation>
#include <QFormLayout>
#include <QVBoxLayout>

namespace ventilator {
namespace modes {
    PCV::PCV(QWidget * parent) 
        : QScrollArea(parent)
        , is_expanded_(true)
    {
        setContentsMargins(0, 0, 0, 0);
        setMinimumHeight(0);

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

        animation_ = new QPropertyAnimation(this, "maximumHeight");
        animation_->setStartValue(0);
        animation_->setEndValue(layout->sizeHint().height());
        animation_->setDuration(200);
    }

    PCV::~PCV() {}

    void
    PCV::collapse() {
        animation_->setDirection(QAbstractAnimation::Backward);
        if (is_expanded_) {
            is_expanded_ = false;
            animation_->start();
        }
    }

    void
    PCV::expand() {
        animation_->setDirection(QAbstractAnimation::Forward);
        if (!is_expanded_) {
            is_expanded_ = true;
            animation_->start();
        }
    }
} // namesp:ace modes
} // namespace ventilator
