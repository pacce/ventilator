#ifndef VENTILATOR_VENTILATOR_MODES_PCV_HPP__
#define VENTILATOR_VENTILATOR_MODES_PCV_HPP__

#include <QPropertyAnimation>
#include <QWidget>

#include "spinbox-frequency.hpp"
#include "spinbox-peep.hpp"
#include "spinbox-pressure-peak.hpp"
#include "spinbox-ratio.hpp"

#include "ventilator-setup.hpp"

namespace ventilator {
namespace modes {
    class PCV : public QWidget {
        Q_OBJECT
        public:
            PCV(QWidget * parent = nullptr);
            ~PCV();

            void collapse();
            void expand();
            
            ventilator::setup::PCV<double> setup() const;
        signals:
            void value(const ventilator::setup::PCV<double>) const;
        private:
            spinbox::PEEP *             peep_;
            spinbox::pressure::Peak *   peak_;
            spinbox::Frequency *        frequency_;
            spinbox::Ratio *            ratio_;

            QPropertyAnimation *        animation_;
            bool                        is_expanded_;
    };
} // namespace modes
} // namespace ventilator

#endif // VENTILATOR_VENTILATOR_MODES_PCV_HPP__
