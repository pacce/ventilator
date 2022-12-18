#include "ventilator-vcv.hpp"

#include <QAbstractAnimation>
#include <QFormLayout>
#include <QVBoxLayout>

namespace ventilator {
namespace modes {
    VCV::VCV(QWidget * parent) 
        : QWidget(parent)
        , is_expanded_(true)
    {
        setContentsMargins(0, 0, 0, 0);
        setMinimumHeight(0);

        peep_       = new spinbox::PEEP;
        frequency_  = new spinbox::Frequency;
        ratio_      = new spinbox::Ratio;

        QFormLayout * form = new QFormLayout;
        form->addRow("Positive End-Expiratory Pressure (cmH<sub>2</sub>O)", peep_);
        form->addRow("Respiratory Rate (bpm)", frequency_);
        form->addRow("Inspiratory:Expiratory Ratio", ratio_);

        QVBoxLayout * layout = new QVBoxLayout;
        layout->addLayout(form);

        setLayout(layout);
        connect(
                  peep_
                , &spinbox::PEEP::peep
                , this
                , [this](){ emit value(this->setup()); }
                );
        connect(
                  frequency_
                , &spinbox::Frequency::frequency
                , this
                , [this](){ emit value(this->setup()); }
                );
        connect(
                  ratio_
                , &spinbox::Ratio::ratio
                , this
                , [this](){ emit value(this->setup()); }
                );

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

    ventilator::setup::VCV<double>
    VCV::setup() const {
        return ventilator::setup::VCV<double>(
                  peep_->get()
                // , peak_->get()
                , frequency_->get()
                , ratio_->get()
                );
    }
} // namespace modes
} // namespace ventilator
