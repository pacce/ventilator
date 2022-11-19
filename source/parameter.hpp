#ifndef VENTILATOR_PARAMETER_HPP__
#define VENTILATOR_PARAMETER_HPP__

#include <QDoubleValidator>
#include <QDoubleSpinBox>
#include <QWidget>

namespace ventilator {
    class Parameter : public QDoubleSpinBox {
        Q_OBJECT
        public:
            Parameter(QWidget * parent = 0);
            ~Parameter();
        private:
            QDoubleValidator * validator_;
    };

} // namespace ventilator

#endif // VENTILATOR_PARAMETER_HPP__
