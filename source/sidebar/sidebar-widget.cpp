#include "sidebar-widget.hpp"

#include <QVBoxLayout>
#include "ventilator-configuration.hpp"

namespace ventilator {
namespace sidebar {
    Sidebar::Sidebar(QWidget * parent)
        : QFrame(parent)
    {
        setMaximumWidth(500);

        lung_ = new lung::Lung(configuration::COMPLIANCE_MILILITER, configuration::RESISTANCE);
        ventilator_ = new ventilator::Ventilator;

        QVBoxLayout * layout = new QVBoxLayout;
        layout->addWidget(lung_);
        layout->addWidget(ventilator_);
        layout->setAlignment(Qt::AlignTop);
        setLayout(layout);

        connect(lung_, &lung::Lung::compliance, this, &Sidebar::compliance);
        connect(lung_, &lung::Lung::resistance, this, &Sidebar::resistance);

        connect(ventilator_, &ventilator::Ventilator::vcv, this, &Sidebar::vcv);
        connect(ventilator_, &ventilator::Ventilator::pcv, this, &Sidebar::pcv);
    }

    Sidebar::~Sidebar() {}
} // namespace sidebar
} // namespace ventilator
