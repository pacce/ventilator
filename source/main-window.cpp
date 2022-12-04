#include "main-window.hpp"

#include <iostream>
#include <cmath>
#include <QChartView>
#include <QTimer>
#include <QValueAxis>
#include <QHBoxLayout>

#include "ventilator.hpp"

Ventilator::Ventilator(QWidget * parent)
    : QMainWindow(parent)
{
    charts_     = new ventilator::charts::Charts;
    engine_     = new ventilator::Engine;
    sidebar_   = new ventilator::sidebar::SideBar;
    pcv_        = new ventilator::pcv::PCV;

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget(sidebar_);
    layout->addWidget(charts_);
    layout->addWidget(pcv_);

    QWidget * widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);

    QTimer * timer = new QTimer(this);
    connect(timer, &QTimer::timeout, engine_, &ventilator::Engine::step);

    connect(engine_
            , &ventilator::Engine::packet
            , charts_
            , [this](const ventilation::Packet<double>& p) { charts_->update(p); }
            );
    connect(sidebar_
            , &ventilator::sidebar::SideBar::compliance
            , engine_
            , &ventilator::Engine::compliance
            );
    connect(sidebar_
            , &ventilator::sidebar::SideBar::resistance
            , engine_
            , &ventilator::Engine::resistance
            );
    connect(sidebar_
            , &ventilator::sidebar::SideBar::peep
            , engine_
            , &ventilator::Engine::peep
            );
// =======
//     connect(pcv_, &ventilator::pcv::PCV::peep, engine_, &ventilator::Engine::peep);
//     connect(pcv_, &ventilator::pcv::PCV::peak, engine_, &ventilator::Engine::peak);
// >>>>>>> 61cbd6f (feat: adds a pcv peep and pressure control)
    timer->start(10);
}

Ventilator::~Ventilator()
{}
