#include "ventilator-widget.hpp"

#include <QFormLayout>

namespace ventilator {
    Ventilator::Ventilator(QWidget * parent)
        : QFrame(parent)
    {
        peep_ = new spinbox::PEEP;

        QFormLayout * layout = new QFormLayout;
        layout->addRow("PEEP (cmH<sub>2</sub>O)", peep_);
        setLayout(layout);

        connect(peep_
                , &spinbox::PEEP::peep
                , this
                , [this](const ventilation::PEEP<double>& p) { emit peep(p); }
                );
    }

    Ventilator::~Ventilator() {}
} // namespace ventilator