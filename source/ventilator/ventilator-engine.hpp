#ifndef VENTILATOR_ENGINE_HPP__
#define VENTILATOR_ENGINE_HPP__

#include <chrono>
#include <QWidget>
#include <variant>
#include <ventilation/ventilation.hpp>

#include "ventilator-modes/ventilator-setup.hpp"

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

            void pcv(const ventilator::setup::PCV<double>& setup);
            void vcv(const ventilator::setup::VCV<double>& setup);
        private:
            std::chrono::duration<double>   step_;

            ventilation::lung::Forward<double>  lung_;

            ventilation::frequency::Frequency<double>   frequency_;
            ventilation::ratio::Ratio<double>           ratio_;
            ventilation::cycle::Cycle<double>           cycle_;

            ventilation::Modes<double>          ventilator_;
            ventilation::modes::Names           mode_;
    };
} // namespace ventilator

#endif // VENTILATOR_ENGINE_HPP__
