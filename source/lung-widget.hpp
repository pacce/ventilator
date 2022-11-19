#ifndef LUNG_WIDGET_HPP__
#define LUNG_WIDGET_HPP__

#include <cstdint>

#include <QFrame>
#include <QLabel>
#include <QWidget>

#include "parameter.hpp"

namespace ventilator {

class Lung : public QFrame {
    Q_OBJECT
    public:
        Lung(QWidget * parent = nullptr);
        ~Lung();
    private:
        QLabel * label_;
        Parameter * compliance_;
};

} // namespace ventilator

#endif // LUNG_WIDGET_HPP__
