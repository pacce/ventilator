#ifndef VENTILATOR_WIDGET_HPP__
#define VENTILATOR_WIDGET_HPP__

#include <chrono>
#include <QWidget>
#include <memory>
#include <ventilation/ventilation.hpp>

namespace ventilator {
    class Ventilator : public QWidget {
        Q_OBJECT
        public:
            Ventilator(QWidget * parent = 0);
            ~Ventilator();
        signals:
            void pressure(const ventilation::Pressure<double>& p);
            void flow(const ventilation::Flow<double>& f);
            void volume(const ventilation::Volume<double>& f);
        public slots:
            void
            step();
        private:
            std::chrono::duration<double>   step_;

            ventilation::lung::Forward<double>          lung_;
            ventilation::cycle::Cycle<double>           cycle_;
            std::unique_ptr<ventilation::Mode<double>>  ventilator_;
    };
} // namespace ventilator

#endif // VENTILATOR_WIDGET_HPP__