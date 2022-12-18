#include "ventilator-engine.hpp"
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

    using Frequency = ventilation::frequency::Frequency<double>;
    using Ratio     = ventilation::ratio::Ratio<double>;
    using duration  = std::chrono::duration<double>;

    Engine::Engine(QWidget * parent)
        : QWidget(parent)
        , step_(100us)
        , lung_(Resistance(50.0), Compliance(30.0e-3))
        , frequency_(Frequency(0.5))
        , ratio_(1.0, 4.0)
        , cycle_(frequency_, ratio_)
    {
        ventilator_ = ventilation::modes::PCV<double>(PEEP(5.0), Peak(20.0), cycle_);
        mode_       = ventilation::modes::Names::PCV;
    }

    Engine::~Engine() {}

    void
    Engine::step() {
        duration total      = 10ms;
        duration current    = 0s;

        std::vector<Packet> ps;
        while (current <= total) {
            current += step_;
            switch(mode_) {
                case ventilation::modes::Names::EMPTY:
                { break; }
                case ventilation::modes::Names::PCV:
                { ps.push_back(std::get<1>(ventilator_)(lung_, step_)); break; }
                case ventilation::modes::Names::VCV:
                { ps.push_back(std::get<2>(ventilator_)(lung_, step_)); break; }
            }
        }
        Packet p = ventilation::mean(ps);

        emit pressure(p.pressure);
        emit flow(p.flow);
        emit volume(p.volume);

        emit packet(p);
    }

    void
    Engine::compliance(const ventilation::Compliance<double>& c) {
        lung_ = ventilation::lung::Forward(lung_.resistance(), c);
    }

    void
    Engine::resistance(const ventilation::Resistance<double>& r) {
        lung_ = ventilation::lung::Forward(r, lung_.elastance());
    }

    void
    Engine::pcv(const ventilator::setup::PCV<double>& setup) {
        mode_   = ventilation::modes::Names::PCV;

        ratio_  = setup.ratio;
        cycle_  = setup.cycle();
        
        ventilator_ = ventilation::modes::PCV<double>(setup.peep, setup.peak, cycle_);
    }

    void
    Engine::vcv(const ventilator::setup::VCV<double>& setup) {
        mode_   = ventilation::modes::Names::VCV;

        ratio_  = setup.ratio;
        cycle_  = setup.cycle();

        ventilator_ = ventilation::modes::VCV<double>(setup.peep, Flow(1.0), cycle_);
    }
} // namespace ventilator
