#ifndef VENTILATION_LUNG_WIDGET_HPP__
#define VENTILATION_LUNG_WIDGET_HPP__

#include <cstdint>
#include <QFrame>
#include <ventilation/ventilation.hpp>

#include "lung-compliance.hpp"
#include "spinbox-resistance.hpp"

namespace ventilator {
namespace lung {
    class Lung : public QFrame {
        Q_OBJECT
        public:
            Lung(QWidget * parent = nullptr);
            ~Lung();
        signals:
            void compliance(const ventilation::Compliance<double>& c) const;
            void resistance(const ventilation::Resistance<double>& r) const;
        private:
            Compliance * compliance_;
            spinbox::Resistance * resistance_;
    };
} // namespace lung
} // namespace ventilator

#endif // VENTILATION_LUNG_WIDGET_HPP__
