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

    flow_->set_yrange(-0.5, 0.5);
    flow_->set_title("Flow (L/s)");

    pressure_->set_yrange(0, 30.0);
    pressure_->set_title("Pressure (cmH2O)");

    volume_->set_yrange(0, 0.6);
    volume_->set_title("Volume (L)");

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(flow_);
    layout->addWidget(pressure_);
    layout->addWidget(volume_);

    QWidget * widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);

    v = new ventilator::Ventilator;

    QTimer * timer = new QTimer(this);
    connect(timer, &QTimer::timeout, v, &ventilator::Ventilator::step);

    connect(v
            , &ventilator::Ventilator::flow
            , flow_
            , [this](const ventilation::Flow<double>& p) { flow_->update(p); }
            );
    connect(v
            , &ventilator::Ventilator::pressure
            , pressure_
            , [this](const ventilation::Pressure<double>& p) { pressure_->update(p); }
            );
    connect(v
            , &ventilator::Ventilator::volume
            , flow_
            , [this](const ventilation::Volume<double>& p) { volume_->update(p); }
            );
    timer->start(10);
}

Ventilator::~Ventilator()
{}
