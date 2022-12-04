#include "side-bar-widget.hpp"

#include <QVBoxLayout>

namespace ventilator {
namespace sidebar {
    SideBar::SideBar(QWidget * parent)
        : QFrame(parent)
    {
        lung_ = new lung::Lung;

        QVBoxLayout * layout = new QVBoxLayout;
        layout->addWidget(lung_);
        setLayout(layout);

        connect(lung_, &lung::Lung::compliance, this, &SideBar::compliance);
        connect(lung_, &lung::Lung::resistance, this, &SideBar::resistance);
    }

    SideBar::~SideBar() {}
} // namespace sidebar
} // namespace ventilator
