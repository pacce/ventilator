#ifndef VENTILATOR_SPINBOX_PEEP_HPP__
#define VENTILATOR_SPINBOX_PEEP_HPP__

#include <QDoubleValidator>
#include <QDoubleSpinBox>
#include <ventilation/ventilation.hpp>

namespace ventilator {
namespace spinbox {
    class PEEP : public QDoubleSpinBox {
        Q_OBJECT
        public:
            PEEP(QWidget * parent = nullptr);
            PEEP(const ventilation::PEEP<double>& p, QWidget * parent = nullptr);
            ~PEEP();

            ventilation::PEEP<double> get() const;
        signals:
            void peep(ventilation::PEEP<double>) const;
        private slots:
            void update(double);
        private:
            QDoubleValidator *  validator_;
    };
} // namespace spinbox
} // namespace ventilator

#endif // VENTILATOR_SPINBOX_PEEP_HPP__
