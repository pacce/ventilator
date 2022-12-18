#include "sidebar-widget.hpp"

#include <QVBoxLayout>

namespace ventilator {
namespace sidebar {
    Sidebar::Sidebar(QWidget * parent)
        : QFrame(parent)
    {
        setMaximumWidth(500);

        lung_ = new lung::Lung;
        ventilator_ = new ventilator::Ventilator;

        QVBoxLayout * layout = new QVBoxLayout;
        layout->addWidget(lung_);
        layout->addWidget(ventilator_);
        setLayout(layout);

        connect(lung_, &lung::Lung::compliance, this, &Sidebar::compliance);
        connect(lung_, &lung::Lung::resistance, this, &Sidebar::resistance);
        connect(ventilator_, &ventilator::Ventilator::peep, this, &Sidebar::peep);
        connect(ventilator_, &ventilator::Ventilator::peak, this, &Sidebar::peak);
        connect(ventilator_, &ventilator::Ventilator::mode, this, &Sidebar::mode);
    }

    Sidebar::~Sidebar() {}
} // namespace sidebar
} // namespace ventilator
