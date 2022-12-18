#ifndef VENTILATOR_ENGINE_HPP__
#define VENTILATOR_ENGINE_HPP__

#include <chrono>
#include <QWidget>
#include <variant>
#include <ventilation/ventilation.hpp>

namespace ventilator {
    class Engine : public QWidget {
        Q_OBJECT
        public:
            Engine(QWidget * parent = 0);
            ~Engine();
        signals:
            void pressure(const ventilation::Pressure<double>& p);
            void flow(const ventilation::Flow<double>& f);
            void volume(const ventilation::Volume<double>& v);
            void packet(const ventilation::Packet<double>& packet);
        public slots:
            void step();
            void compliance(const ventilation::Compliance<double>& c);
            void resistance(const ventilation::Resistance<double>& r);
            void peep(const ventilation::PEEP<double>& peep);
            void peak(const ventilation::pressure::Peak<double>& peak);
            void mode(const ventilation::modes::Names& names);
        private:
            std::chrono::duration<double>   step_;

            ventilation::lung::Forward<double>  lung_;
            ventilation::cycle::Cycle<double>   cycle_;
            ventilation::Modes<double>          ventilator_;
            ventilation::modes::Names           mode_;
    };
} // namespace ventilator

#endif // VENTILATOR_ENGINE_HPP__
