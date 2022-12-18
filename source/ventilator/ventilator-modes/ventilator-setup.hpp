#ifndef VENTILATOR_VENTILATOR_SETUP_HPP__
#define VENTILATOR_VENTILATOR_SETUP_HPP__

#include <ventilation/ventilation.hpp>

namespace ventilator {
namespace setup {
    template <typename Precision> using PEEP = ventilation::PEEP<Precision>;
    template <typename Precision> using Peak = ventilation::pressure::Peak<Precision>;

    template <typename Precision> using Flow = ventilation::Flow<Precision>;

    template <typename Precision> using Frequency   = ventilation::frequency::Frequency<Precision>;
    template <typename Precision> using Ratio       = ventilation::ratio::Ratio<Precision>;
    template <typename Precision> using Cycle       = ventilation::cycle::Cycle<Precision>;

    template <typename Precision>
    struct PCV {
        PEEP<Precision>         peep;
        Peak<Precision>         peak;
        Frequency<Precision>    frequency;
        Ratio<Precision>        ratio;

        Cycle<Precision> cycle() const { return Cycle<Precision>(frequency, ratio); }
    };

    template <typename Precision>
    struct VCV {
        PEEP<Precision>         peep;
        // Flow<Precision>         peak;
        Frequency<Precision>    frequency;
        Ratio<Precision>        ratio;

        Cycle<Precision> cycle() const { return Cycle<Precision>(frequency, ratio); }
    };
} // namespace setup
} // namespace ventilator

#endif // VENTILATOR_VENTILATOR_SETUP_HPP__
