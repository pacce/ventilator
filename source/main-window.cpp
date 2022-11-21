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
    
    lung_       = new ventilator::lung::Lung;
    engine_     = new ventilator::Engine;

    ventilator_ = new ventilator::Ventilator;

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(charts_);
    layout->addWidget(lung_);
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
    connect(lung_
            , &ventilator::lung::Lung::compliance
            , engine_
            , &ventilator::Engine::compliance
            );
    connect(lung_
            , &ventilator::lung::Lung::resistance
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
