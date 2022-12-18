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
    sidebar_    = new ventilator::sidebar::Sidebar;

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget(sidebar_);
    layout->addWidget(charts_);

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
            , &ventilator::sidebar::Sidebar::compliance
            , engine_
            , &ventilator::Engine::compliance
            );
    connect(sidebar_
            , &ventilator::sidebar::Sidebar::resistance
            , engine_
            , &ventilator::Engine::resistance
            );
    connect(sidebar_
            , &ventilator::sidebar::Sidebar::peep
            , engine_
            , &ventilator::Engine::peep
            );
    connect(sidebar_
            , &ventilator::sidebar::Sidebar::peak
            , engine_
            , &ventilator::Engine::peak
            );
    connect(sidebar_
            , &ventilator::sidebar::Sidebar::mode
            , engine_
            , &ventilator::Engine::mode
            );
    connect(sidebar_
            , &ventilator::sidebar::Sidebar::frequency
            , engine_
            , &ventilator::Engine::frequency
            );
    connect(sidebar_
            , &ventilator::sidebar::Sidebar::ratio
            , engine_
            , &ventilator::Engine::ratio
            );
    timer->start(10);
}

Ventilator::~Ventilator()
{}
