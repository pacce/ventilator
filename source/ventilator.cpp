#include "ventilator.hpp"
#include <iostream>

namespace ventilator {
    using namespace std::chrono_literals;

    using Compliance    = ventilation::Compliance<double>;
    using Elastance     = ventilation::Elastance<double>;
    using Resistance    = ventilation::Resistance<double>;

    using Flow      = ventilation::Flow<double>;
    using Pressure  = ventilation::Pressure<double>;
    using PEEP      = ventilation::PEEP<double>;
    using Peak      = ventilation::pressure::Peak<double>;
    using Volume    = ventilation::Volume<double>;
    using Packet    = ventilation::Packet<double>;

    using duration  = std::chrono::duration<double>;

    Ventilator::Ventilator(QWidget * parent)
        : QWidget(parent)
        , step_(100us)
        , lung_(Resistance(50.0), Compliance(30.0e-3))
        , cycle_(duration(0.6), duration(2.4))
    {
        // ventilator_ = std::make_unique<ventilation::modes::PCV<double>>(
        //           PEEP(5.0)
        //         , Peak(20.0)
        //         , cycle_
        //         );
        ventilator_ = std::make_unique<ventilation::modes::VCV<double>>(
                  PEEP(5.0)
                , Flow(1.0)
                , cycle_
                );
    }

    Ventilator::~Ventilator() {}

    void
    Ventilator::step() {
        duration total      = 10ms;
        duration current    = 0s;

        std::vector<Packet> ps;
        while (current <= total) {
            current += step_;
            ps.push_back(ventilator_->operator()(lung_, step_));
        }
        double den  = 1.0 / static_cast<double>(ps.size());
        Packet p  = std::accumulate(
                  ps.begin()
                , ps.end()
                , Packet()
                , [=](Packet acc, Packet v) { return (v * den) + acc; }
                );
        emit flow(p.flow);
        emit pressure(p.pressure);
        emit volume(p.volume);
    }

    void
    Ventilator::compliance(const ventilation::Compliance<double>& c) {
        lung_ = ventilation::lung::Forward(lung_.resistance(), c);
    }

    void
    Ventilator::resistance(const ventilation::Resistance<double>& r) {
        lung_ = ventilation::lung::Forward(r, lung_.elastance());
    }
} // namespace ventilator
