#include "ventilator-widget.hpp"

#include <QVBoxLayout>

namespace ventilator {
    Ventilator::Ventilator(QWidget * parent)
        : QGroupBox(parent)
    {
        pcv_ = new ventilator::modes::PCV;
        vcv_ = new ventilator::modes::VCV;

        QPushButton * pcv_button = new QPushButton();
        pcv_button->setFlat(true);
        pcv_button->setText("Pressure Controlled Ventilation");
        pcv_button->setStyleSheet("text-align: left");

        QPushButton * vcv_button = new QPushButton();
        vcv_button->setFlat(true);
        vcv_button->setText("Volume Controlled Ventilation");
        vcv_button->setStyleSheet("text-align: left");

        QVBoxLayout * layout = new QVBoxLayout;
        layout->addWidget(pcv_button);
        layout->addWidget(pcv_);
        layout->addWidget(vcv_button);
        layout->addWidget(vcv_);
        layout->addStretch(1);
        setLayout(layout);
        setTitle("Ventilator");

        connect(vcv_, &ventilator::modes::VCV::value, this, &Ventilator::vcv);
        connect(pcv_, &ventilator::modes::PCV::value, this, &Ventilator::pcv);

        connect(
                  pcv_button
                , &QAbstractButton::clicked
                , this
                , [this]() {
                    if (!pcv_->is_expanded()) {
                        pcv_->expand();
                        vcv_->collapse();

                        emit pcv(pcv_->setup());
                    }
                });
        connect(
                  vcv_button
                , &QAbstractButton::clicked
                , this
                , [this]() {
                    if (!vcv_->is_expanded()) {
                        pcv_->collapse();
                        vcv_->expand();

                        emit vcv(vcv_->setup());
                    }
                });
    }

    Ventilator::~Ventilator() {}
} // namespace ventilator
