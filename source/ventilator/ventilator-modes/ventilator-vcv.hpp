#ifndef VENTILATOR_VENTILATOR_MODES_VCV_HPP__
#define VENTILATOR_VENTILATOR_MODES_VCV_HPP__

#include <QPropertyAnimation>
#include <QWidget>

#include "spinbox-frequency.hpp"
#include "spinbox-peep.hpp"
#include "spinbox-pressure-peak.hpp"
#include "spinbox-ratio.hpp"

#include "ventilator-setup.hpp"

namespace ventilator {
namespace modes {
    class VCV : public QWidget {
        Q_OBJECT
        public:
            VCV(QWidget * parent = nullptr);
            ~VCV();

            void collapse();
            void expand();

            ventilator::setup::VCV<double> setup() const;
        signals:
            void value(const ventilator::setup::VCV<double>) const;
        private:
            spinbox::PEEP *             peep_;
            spinbox::Frequency *        frequency_;
            spinbox::Ratio *            ratio_;

            QPropertyAnimation *        animation_;
            bool                        is_expanded_;
    };
} // namespace modes
} // namespace ventilator

#endif // VENTILATOR_VENTILATOR_MODES_VCV_HPP__
