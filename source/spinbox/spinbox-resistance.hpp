#ifndef VENTILATOR_SPINBOX_RESISTANCE_HPP__
#define VENTILATOR_SPINBOX_RESISTANCE_HPP__

#include <QDoubleValidator>
#include <QDoubleSpinBox>
#include <ventilation/ventilation.hpp>

namespace ventilator {
namespace spinbox {
    class Resistance : public QDoubleSpinBox {
        Q_OBJECT
        public:
            Resistance(QWidget * parent = nullptr);
            Resistance(const ventilation::Resistance<double>& r, QWidget * parent = nullptr);
            ~Resistance();
        signals:
            void resistance(ventilation::Resistance<double>) const;
        private slots:
            void update(double);
        private:
            QDoubleValidator *  validator_;
    };
} // namespace spinbox
} // namespace ventilator

#endif // VENTILATOR_SPINBOX_RESISTANCE_HPP__
