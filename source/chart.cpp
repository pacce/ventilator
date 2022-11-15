#include "chart.hpp"

#include <QChartView>
#include <QVBoxLayout>

namespace ventilator {
    Chart::Chart(QWidget * parent)
        : QWidget(parent)
        , chart_(new QChart)
        , series_(new QLineSeries)
        , counter_(0)
        , samples_(2000)
    {
        QChartView * view = new QChartView(chart_);

        chart_->legend()->hide(); // Hides annoying blue square
        chart_->addSeries(series_);
        chart_->createDefaultAxes();

        QVBoxLayout * layout = new QVBoxLayout(this);
        layout->addWidget(view);

        this->set_xrange(counter_, samples_);
    }

    Chart::~Chart() {}

    void
    Chart::set_xrange(float start, float finish) {
        chart_->axes(Qt::Horizontal).first()->setRange(start, finish);
    }

    void
    Chart::set_yrange(float start, float finish) {
        chart_->axes(Qt::Vertical).first()->setRange(start, finish);
    }

    void
    Chart::set_title(const QString& title) {
        chart_->setTitle(title);
    }

    void
    Chart::update(const ventilation::Flow<double>& v) {
        this->update(static_cast<double>(v));
    }

    void
    Chart::update(const ventilation::Flow<float>& v) {
        this->update(static_cast<float>(v));
    }

    void
    Chart::update(const ventilation::Pressure<double>& v) {
        this->update(static_cast<double>(v));
    }

    void
    Chart::update(const ventilation::Pressure<float>& v) {
        this->update(static_cast<float>(v));
    }

    void
    Chart::update(const ventilation::Volume<double>& v) {
        this->update(static_cast<double>(v));
    }

    void
    Chart::update(const ventilation::Volume<float>& v) {
        this->update(static_cast<float>(v));
    }

    void
    Chart::update(float value) {
        QPointF sample(counter_, value);
        if (vs_.size() < samples_) {
            vs_.push_back(sample);
        } else {
            vs_[counter_] = sample;
        }
        series_->replace(vs_);
        counter_ = (counter_ + 1) % samples_;
    }
} // namespace ventilator
