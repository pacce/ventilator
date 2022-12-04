#include "main-window.hpp"

#include <iostream>
#include <cmath>
#include <QChartView>
#include <QTimer>
#include <QValueAxis>
#include <QVBoxLayout>

#include "ventilator.hpp"

Ventilator::Ventilator(QWidget * parent)
    : QMainWindow(parent)
{
    charts_     = new ventilator::charts::Charts;
    engine_     = new ventilator::Engine;
    side_bar_   = new ventilator::sidebar::SideBar;
    ventilator_ = new ventilator::Ventilator;

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(charts_);
    layout->addWidget(side_bar_);
    layout->addWidget(ventilator_);

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
    connect(side_bar_
            , &ventilator::sidebar::SideBar::compliance
            , engine_
            , &ventilator::Engine::compliance
            );
    connect(side_bar_
            , &ventilator::sidebar::SideBar::resistance
            , engine_
            , &ventilator::Engine::resistance
            );
    connect(ventilator_
            , &ventilator::Ventilator::peep
            , engine_
            , &ventilator::Engine::peep
            );
    timer->start(10);
}

Ventilator::~Ventilator()
{}
