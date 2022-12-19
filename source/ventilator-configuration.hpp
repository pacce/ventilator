#ifndef VENTILATOR_CONFIGURATION_HPP__
#define VENTILATOR_CONFIGURATION_HPP__

#include <ventilation/ventilation.hpp>

namespace ventilator {
namespace configuration {
    using namespace ventilation::frequency::literals;

    const ventilation::Resistance<double>   RESISTANCE(50.0);
    const ventilation::Compliance<double>   COMPLIANCE_MILILITER(30.0);
    const ventilation::Compliance<double>   COMPLIANCE_LITER(30.0e-3);

    const ventilation::PEEP<double>             PEEP( 5.0);
    const ventilation::pressure::Peak<double>   PEAK(20.0);

    const double INSIPIRATORY_RATIO = 1.0;
    const double EXPIRATORY_RATIO   = 4.0;
    const double RESPIRATORY_RATE                               = 30.0;
    const ventilation::frequency::Frequency<double> FREQUENCY   = 30_bpm;

} // namespace configuration
} // namespace ventilator

#endif // VENTILATOR_CONFIGURATION_HPP__
