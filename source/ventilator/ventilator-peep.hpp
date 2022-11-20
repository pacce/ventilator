#ifndef VENTILATOR_PEEP_HPP__
#define VENTILATOR_PEEP_HPP__

#include <QDoubleValidator>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QWidget>
#include <ventilation/ventilation.hpp>

namespace ventilator {
    class PEEP : public QDoubleSpinBox {
        Q_OBJECT
        public:
            PEEP(QWidget * parent = nullptr);
            ~PEEP();
        signals:
            void peep(ventilation::PEEP<double>) const;
        private slots:
            void update(double);
        private:
            QDoubleValidator *  validator_;
    };
} // namespace ventilator

#endif // VENTILATOR_PEEP_HPP__
