#ifndef VENTILATOR_VENTILATOR_MODES_VCV_HPP__
#define VENTILATOR_VENTILATOR_MODES_VCV_HPP__

#include <QLabel>
#include <QWidget>

#include "spinbox-peep.hpp"
#include "spinbox-pressure-peak.hpp"

namespace ventilator {
namespace modes {
    class VCV : public QWidget {
        Q_OBJECT
        public:
            VCV(QWidget * parent = nullptr);
            ~VCV();
        signals:
            void peep(ventilation::PEEP<double>) const;
        private:
            QLabel *                    label_;
            spinbox::PEEP *             peep_;
            spinbox::pressure::Peak *   peak_;
    };
} // namespace modes
} // namespace ventilator

#endif // VENTILATOR_VENTILATOR_MODES_VCV_HPP__
