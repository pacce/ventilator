#ifndef VENTILATOR_CONFIGURATION_HPP__
#define VENTILATOR_CONFIGURATION_HPP__

#include <ventilation/ventilation.hpp>

namespace ventilator {
namespace configuration {
    const ventilation::Resistance<double> RESISTANCE(50.0);
    const ventilation::Compliance<double> COMPLIANCE(30.0);
} // namespace configuration
} // namespace ventilator

#endif // VENTILATOR_CONFIGURATION_HPP__
