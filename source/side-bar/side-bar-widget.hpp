#ifndef SIDE_BAR_WIDGET_HPP__
#define SIDE_BAR_WIDGET_HPP__

#include <cstdint>
#include <QFrame>
#include <QWidget>

#include "lung.hpp"

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
        private:
            lung::Lung * lung_;
    };
} // namespace sidebar
} // namespace ventilator

#endif // SIDE_BAR_WIDGET_HPP__
