#ifndef VENTILATOR_SPINBOX_PRESSURE_PEAK_HPP__
#define VENTILATOR_SPINBOX_PRESSURE_PEAK_HPP__
#include <QDoubleValidator>
#include <QDoubleSpinBox>
#include <ventilation/ventilation.hpp>

namespace ventilator {
namespace spinbox {
namespace pressure {
    class Peak : public QDoubleSpinBox {
        Q_OBJECT
        public:
            Peak(QWidget * parent = nullptr);
            ~Peak();

            ventilation::pressure::Peak<double> get() const;
        signals:
            void pressure(ventilation::pressure::Peak<double>) const;
        private slots:
            void update(double);
        private:
            QDoubleValidator *  validator_;
    };
} // namespace pressure
} // namespace spinbox
} // namespace ventilator

#endif // VENTILATOR_SPINBOX_PRESSURE_PEAK_HPP__
