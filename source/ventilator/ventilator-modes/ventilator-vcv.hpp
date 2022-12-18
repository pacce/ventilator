#ifndef VENTILATOR_VENTILATOR_MODES_VCV_HPP__
#define VENTILATOR_VENTILATOR_MODES_VCV_HPP__

#include <QLabel>
#include <QPropertyAnimation>
#include <QScrollArea>
#include <QWidget>

#include "spinbox-peep.hpp"
#include "spinbox-pressure-peak.hpp"

namespace ventilator {
namespace modes {
    class VCV : public QScrollArea {
        Q_OBJECT
        public:
            VCV(QWidget * parent = nullptr);
            ~VCV();

            void collapse();
            void expand();
        signals:
            void peep(ventilation::PEEP<double>) const;
        private:
            QLabel *                    label_;
            spinbox::PEEP *             peep_;
            spinbox::pressure::Peak *   peak_;
            QPropertyAnimation *        animation_;
            bool                        is_expanded_;
    };
} // namespace modes
} // namespace ventilator

#endif // VENTILATOR_VENTILATOR_MODES_VCV_HPP__
