#include "ventilator.hpp"
#include <iostream>

namespace ventilator {
    using namespace std::chrono_literals;

    using Compliance    = ventilation::Compliance<double>;
    using Elastance     = ventilation::Elastance<double>;
    using Resistance    = ventilation::Resistance<double>;

    using Flow      = ventilation::Flow<double>;
    using Pressure  = ventilation::Pressure<double>;
    using Volume    = ventilation::Volume<double>;

    using duration  = std::chrono::duration<double>;

    Ventilator::Ventilator(QWidget * parent)
        : QWidget(parent)
        , step_(100us)
        , lung_(Resistance(50.0), Compliance(30.0e-3))
        , cycle_(duration(0.6), duration(2.4))
        , ventilator_(Pressure(5.0), Pressure(20.0), cycle_)
    {}

    Ventilator::~Ventilator() {}

    void
    Ventilator::step() {
        duration total      = 10ms;
        duration current    = 0s;

        std::vector<Pressure> ps;
        while (current <= total) {
            current += step_;

            ventilation::modes::Packet packet = ventilator_(lung_, step_);
            ps.push_back(packet.pressure);
        }
        double den  = 1.0 / static_cast<double>(ps.size());
        Pressure p  = std::accumulate(
                ps.begin()
                , ps.end()
                , Pressure()
                , [=](Pressure acc, Pressure v) { return (v * den) + acc; });
        emit pressure(p);
    }
} // namespace ventilator
