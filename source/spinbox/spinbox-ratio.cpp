#include "spinbox-ratio.hpp"

#include <QHBoxLayout>
#include <QLabel>

namespace ventilator {
namespace spinbox {
    Expiration::Expiration(QWidget * parent)
        : QSpinBox(parent)
        , validator_(new QIntValidator(1, 10, this))
    {
        setRange(1, 10);
        connect(this, QOverload<int>::of(&QSpinBox::valueChanged), this, &Expiration::expiration);
    }

    Expiration::~Expiration() {}

    Inspiration::Inspiration(QWidget * parent)
        : QSpinBox(parent)
        , validator_(new QIntValidator(1, 10, this))
    {
        setRange(1, 10);
        connect(this, QOverload<int>::of(&QSpinBox::valueChanged), this, &Inspiration::inspiration);
    }

    Inspiration::~Inspiration() {}

    Ratio::Ratio(QWidget * parent) : QWidget(parent) {
        inspiration_    = new Inspiration;
        expiration_     = new Expiration;

        QHBoxLayout * layout = new QHBoxLayout;
        layout->addWidget(inspiration_);
        layout->addWidget(new QLabel(":"));
        layout->addWidget(expiration_);

        connect( expiration_,   &Expiration::expiration, this,  &Ratio::expiration);
        connect(inspiration_, &Inspiration::inspiration, this, &Ratio::inspiration);

        setLayout(layout);
    }

    Ratio::~Ratio() {}
    
    ventilation::ratio::Ratio<double>
    Ratio::get() const {
        try {
            double i = static_cast<double>(inspiration_->value());
            double e = static_cast<double>( expiration_->value());

            return ventilation::ratio::Ratio<double>(i, e);
        } catch (const std::exception& e) {
            return ventilation::ratio::Ratio<double>(1.0, 1.0);
        }
    }

    void
    Ratio::inspiration(int i) {
        try {
            int e = expiration_->value();
            ventilation::ratio::Ratio<double> r(static_cast<double>(i), static_cast<double>(e));

            emit ratio(r);
        } catch (const std::exception& e) {
        }
    }

    void
    Ratio::expiration(int e) {
        try {
            int i = inspiration_->value();
            ventilation::ratio::Ratio<double> r(static_cast<double>(i), static_cast<double>(e));

            emit ratio(r);
        } catch (const std::exception& e) {
        }
    }
} // namespace spinbox
} // namespace ventilator
