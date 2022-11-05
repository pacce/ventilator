#include "main-window.hpp"

#include <iostream>
#include <QChartView>
#include <QTimer>
#include <QValueAxis>
#include <QVBoxLayout>

Widget::Widget(QWidget * parent)
    : QWidget(parent)
    , chart_(new QChart)
    , series_(new QLineSeries)
    , counter_(0)
{
    chart_->addSeries(series_);

    QChartView * view = new QChartView(chart_);
    view->setMinimumSize(800, 600);

    QValueAxis * xaxis = new QValueAxis;
    QValueAxis * yaxis = new QValueAxis;

    xaxis->setRange(0, 100);
    xaxis->setLabelFormat("%g");
    xaxis->setTitleText("Samples");

    yaxis->setRange(0, 200);
    yaxis->setTitleText("Audio Level");

    chart_->addAxis(xaxis, Qt::AlignBottom);
    chart_->addAxis(yaxis, Qt::AlignLeft);

    QVBoxLayout * layout = new QVBoxLayout(this);
    layout->addWidget(view);

    QTimer * timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::update);
    timer->start(10);
}

Widget::~Widget() {}

void
Widget::update() {
    if (ps_.isEmpty()) {
        ps_.reserve(100);
        for (std::size_t i = 0; i < 100; i++) { ps_.append(QPointF(i, 1)); }
    }
    series_->replace(ps_);
}


Ventilator::Ventilator(QWidget * parent)
    : QMainWindow(parent)
{
    widget_ = new Widget();
    setCentralWidget(widget_);
}

Ventilator::~Ventilator()
{}
