#ifndef VENTILATOR_CHART_HPP__
#define VENTILATOR_CHART_HPP__

#include <QChart>
#include <QLineSeries>
#include <QPointF>
#include <QWidget>
#include <ventilation/ventilation.hpp>

namespace ventilator {
    using namespace QtCharts;

    class Chart : public QWidget {
        Q_OBJECT
        public:
            Chart(QWidget * parent = 0);
            ~Chart();

            void set_xrange(float start, float finish);
            void set_yrange(float start, float finish);
        public slots:
            void update(const ventilation::Flow<double>& p);
            void update(const ventilation::Flow<float>& p);

            void update(const ventilation::Pressure<double>& p);
            void update(const ventilation::Pressure<float>& p);

            void update(const ventilation::Volume<double>& p);
            void update(const ventilation::Volume<float>& p);
        private:
            void update(float value);

            QChart *            chart_;
            QLineSeries *       series_;
            QVector<QPointF>    vs_;

            int counter_;
            int samples_;
    };
} // namespace ventilator

#endif //  VENTILATOR_CHART_HPP__
