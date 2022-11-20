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
    flow_       = new ventilator::Chart;
    pressure_   = new ventilator::Chart;
    volume_     = new ventilator::Chart;
    
    lung_       = new ventilator::lung::Lung;
    engine_     = new ventilator::Engine;

    peep_       = new ventilator::PEEP;

    flow_->set_title("Flow (L/s)");
    pressure_->set_title("Pressure (cmH<sub>2</sub>O)");
    volume_->set_title("Volume (L)");

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(flow_);
    layout->addWidget(pressure_);
    layout->addWidget(volume_);
    layout->addWidget(lung_);
    layout->addWidget(peep_);

    QWidget * widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);

    QTimer * timer = new QTimer(this);
    connect(timer, &QTimer::timeout, engine_, &ventilator::Engine::step);

    connect(engine_
            , &ventilator::Engine::flow
            , flow_
            , [this](const ventilation::Flow<double>& p) { flow_->update(p); }
            );
    connect(engine_
            , &ventilator::Engine::pressure
            , pressure_
            , [this](const ventilation::Pressure<double>& p) { pressure_->update(p); }
            );
    connect(engine_
            , &ventilator::Engine::volume
            , flow_
            , [this](const ventilation::Volume<double>& p) { volume_->update(p); }
            );
    connect(lung_, &ventilator::lung::Lung::compliance, engine_, &ventilator::Engine::compliance);
    connect(lung_, &ventilator::lung::Lung::resistance, engine_, &ventilator::Engine::resistance);
    connect(peep_, &ventilator::PEEP::peep, engine_, &ventilator::Engine::peep);
    timer->start(10);
}

Ventilator::~Ventilator()
{}
