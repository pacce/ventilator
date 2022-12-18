#ifndef VENTILATION_LUNG_WIDGET_HPP__
#define VENTILATION_LUNG_WIDGET_HPP__

#include <cstdint>
#include <QGroupBox>
#include <ventilation/ventilation.hpp>

#include "spinbox-compliance.hpp"
#include "spinbox-resistance.hpp"

namespace ventilator {
namespace lung {
    class Lung : public QGroupBox {
        Q_OBJECT
        public:
            Lung(
                      const ventilation::Compliance<double>& c
                    , const ventilation::Resistance<double>& r
                    , QWidget * parent = nullptr
                    );
            Lung(QWidget * parent = nullptr);
            ~Lung();
        signals:
            void compliance(const ventilation::Compliance<double>& c) const;
            void resistance(const ventilation::Resistance<double>& r) const;
        private:
            spinbox::Compliance * compliance_;
            spinbox::Resistance * resistance_;
    };
} // namespace lung
} // namespace ventilator

#endif // VENTILATION_LUNG_WIDGET_HPP__
