#include "ventilator-pcv.hpp"

#include <QAbstractAnimation>
#include <QFormLayout>
#include <QVBoxLayout>

namespace ventilator {
namespace modes {
    PCV::PCV(QWidget * parent) 
        : QWidget(parent)
        , is_expanded_(true)
    {
        setContentsMargins(0, 0, 0, 0);
        setMinimumHeight(0);

        peep_       = new spinbox::PEEP;
        peak_       = new spinbox::pressure::Peak;
        frequency_  = new spinbox::Frequency;
        ratio_      = new spinbox::Ratio;

        QFormLayout * form = new QFormLayout;
        form->addRow("Positive End-Expiratory Pressure (cmH<sub>2</sub>O)", peep_);
        form->addRow("Peak Pressure (cmH<sub>2</sub>O)", peak_);
        form->addRow("Respiratory Rate (bpm)", frequency_);
        form->addRow("Inspiratory:Expiratory Ratio", ratio_);

        QVBoxLayout * layout = new QVBoxLayout;
        layout->addLayout(form);

        setLayout(layout);
        connect(peep_, &spinbox::PEEP::peep, this, &PCV::peep);
        connect(peak_, &spinbox::pressure::Peak::pressure, this, &PCV::peak);
        connect(frequency_, &spinbox::Frequency::frequency, this, &PCV::frequency);
        connect(ratio_, &spinbox::Ratio::ratio, this, &PCV::ratio);

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
