#ifndef VENTILATOR_VENTILATOR_MODES_PCV_HPP__
#define VENTILATOR_VENTILATOR_MODES_PCV_HPP__

#include <QLabel>
#include <QPropertyAnimation>
#include <QScrollArea>
#include <QWidget>

#include "spinbox-peep.hpp"
#include "spinbox-pressure-peak.hpp"

namespace ventilator {
namespace modes {
    class PCV : public QScrollArea {
        Q_OBJECT
        public:
            PCV(QWidget * parent = nullptr);
            ~PCV();

            void collapse();
            void expand();
        signals:
            void peep(ventilation::PEEP<double>) const;
            void peak(ventilation::pressure::Peak<double>) const;
        private:
            QLabel *                    label_;
            spinbox::PEEP *             peep_;
            spinbox::pressure::Peak *   peak_;
            QPropertyAnimation *        animation_;
            bool                        is_expanded_;
    };
} // namespace modes
} // namespace ventilator

#endif // VENTILATOR_VENTILATOR_MODES_PCV_HPP__
