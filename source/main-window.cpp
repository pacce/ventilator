#include "main-window.hpp"

#include <iostream>
#include <cmath>
#include <QChartView>
#include <QTimer>
#include <QValueAxis>
#include <QVBoxLayout>

#include "ventilator.hpp"

Widget::Widget(QWidget * parent)
    : QWidget(parent)
    , chart_(new QChart)
    , series_(new QLineSeries)
    , range_(500)
    , xi_(0)
    , counter_(0)
{
    xf_ = range_ - 1;

    chart_->addSeries(series_);

    QChartView * view = new QChartView(chart_);
    view->setMinimumSize(800, 600);

    chart_->createDefaultAxes();
    chart_->axes(Qt::Horizontal).first()->setRange(xi_, xf_);
    chart_->axes(Qt::Vertical).first()->setRange(0, 30.0);

    QVBoxLayout * layout = new QVBoxLayout(this);
    layout->addWidget(view);

    ventilator::Ventilator * v = new ventilator::Ventilator(this);

    QTimer * timer = new QTimer(this);
    connect(timer, &QTimer::timeout, v, &ventilator::Ventilator::step);
    connect(v, &ventilator::Ventilator::pressure, this, &Widget::update);
    timer->start(10);
}

Widget::~Widget() {}

void
Widget::update(ventilation::Pressure<double> p) {
    QPointF sample(counter_, static_cast<double>(p));
    if (ps_.size() < static_cast<int>(range_)) {
        ps_.push_back(sample);
    } else {
        ps_.push_back(sample);
        ps_.pop_front();
        chart_->axes(Qt::Horizontal).first()->setRange(++xi_, ++xf_);
    }
    series_->replace(ps_);

    counter_++;
}


Ventilator::Ventilator(QWidget * parent)
    : QMainWindow(parent)
{
    widget_ = new Widget();
    setCentralWidget(widget_);
}

Ventilator::~Ventilator()
{}
