#ifndef SIDE_BAR_WIDGET_HPP__
#define SIDE_BAR_WIDGET_HPP__

#include <cstdint>
#include <QFrame>
#include <QWidget>

#include "lung.hpp"
#include "ventilator.hpp"

namespace ventilator {
namespace sidebar {
    class SideBar : public QFrame {
        Q_OBJECT
        public:
            SideBar(QWidget * parent = nullptr);
            ~SideBar();
        signals:
            void compliance(const ventilation::Compliance<double>& c) const;
            void resistance(const ventilation::Resistance<double>& r) const;
            void peep(const ventilation::PEEP<double>& p) const;
            void peak(const ventilation::pressure::Peak<double>& p) const;
        private:
            lung::Lung *                lung_;
            ventilator::Ventilator *    ventilator_;
    };
} // namespace sidebar
} // namespace ventilator

#endif // SIDE_BAR_WIDGET_HPP__
