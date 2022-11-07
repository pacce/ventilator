#include "main-window.hpp"

#include <iostream>
#include <cmath>
#include <QChartView>
#include <QTimer>
#include <QValueAxis>
#include <QVBoxLayout>

Widget::Widget(QWidget * parent)
    : QWidget(parent)
    , chart_(new QChart)
    , series_(new QLineSeries)
    , range_(20)
    , xi_(0)
    , counter_(0)
{
    xf_ = range_ - 1;

    chart_->addSeries(series_);

    QChartView * view = new QChartView(chart_);
    view->setMinimumSize(800, 600);

    chart_->createDefaultAxes();
    chart_->axes(Qt::Horizontal).first()->setRange(xi_, xf_);
    chart_->axes(Qt::Vertical).first()->setRange(-2, 2);

    QVBoxLayout * layout = new QVBoxLayout(this);
    layout->addWidget(view);

    QTimer * timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::update);
    timer->start(100);
}

Widget::~Widget() {}

void
Widget::update() {
    auto sample = QPointF(counter_, sin(counter_));    

    if (ps_.size() < range_) {
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
