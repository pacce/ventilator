#include "side-bar-widget.hpp"

#include <QVBoxLayout>

namespace ventilator {
namespace sidebar {
    SideBar::SideBar(QWidget * parent)
        : QFrame(parent)
    {
        lung_ = new lung::Lung;
        ventilator_ = new ventilator::Ventilator;

        QVBoxLayout * layout = new QVBoxLayout;
        layout->addWidget(lung_);
        layout->addWidget(ventilator_);
        setLayout(layout);

        connect(lung_, &lung::Lung::compliance, this, &SideBar::compliance);
        connect(lung_, &lung::Lung::resistance, this, &SideBar::resistance);
        connect(ventilator_, &ventilator::Ventilator::peep, this, &SideBar::peep);
        connect(ventilator_, &ventilator::Ventilator::peak, this, &SideBar::peak);
    }

    SideBar::~SideBar() {}
} // namespace sidebar
} // namespace ventilator
