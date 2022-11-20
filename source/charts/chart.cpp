#include "chart.hpp"

#include <QChartView>
#include <QVBoxLayout>

namespace ventilator {
namespace charts {
    Chart::Chart(QWidget * parent)
        : QWidget(parent)
        , chart_(new QChart)
        , series_(new QLineSeries)
        , counter_(0)
        , samples_(2000)
        , y_max(0)
        , y_min(0)
    {
        QChartView * view = new QChartView(chart_);

        chart_->legend()->hide(); // Hides annoying blue square
        chart_->addSeries(series_);
        chart_->createDefaultAxes();

        QVBoxLayout * layout = new QVBoxLayout(this);
        layout->addWidget(view);

        this->set_xrange(counter_, samples_);
        this->set_yrange(y_min, y_max);
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

        scale_max_range(value);
        if (counter_ == 0) {
            auto_scale();
        }
        counter_ = (counter_ + 1) % samples_;
    }

    void
    Chart::scale_max_range(float value) {
        if ((y_max < value) || (y_min > value)) {
            if (y_max < value) {
                y_max = value;
            } else {
                y_min = value;
            }
            set_yrange(y_min, y_max);
        }
    }

    void
    Chart::auto_scale() {
        auto points = series_->points();
        std::sort(
            points.begin()
            , points.end()
            , [](const QPointF &p1, const QPointF &p2) {
                return p1.y() < p2.y();
            }
        );

        y_min = points.first().y();
        y_max = points.last().y();
        set_yrange(y_min, y_max);
    }
} // namespace charts
} // namespace ventilator
