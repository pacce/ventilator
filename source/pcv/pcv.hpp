#ifndef VENTILATOR_PCV_HPP__
#define VENTILATOR_PCV_HPP__

#include <QWidget>

#include "spinbox-peep.hpp"
#include "spinbox-pressure-peak.hpp"

namespace ventilator {
namespace pcv {
    class PCV : public QWidget {
        Q_OBJECT
        public:
            PCV(QWidget * parent = nullptr);
            ~PCV();
        signals:
            void peep(ventilation::PEEP<double>) const;
            void peak(ventilation::pressure::Peak<double>) const;
        private:
            spinbox::PEEP *             peep_;
            spinbox::pressure::Peak *   peak_;
    };
} // namespace pcv
} // namespace ventilator

#endif // VENTILATOR_PCV_HPP__
