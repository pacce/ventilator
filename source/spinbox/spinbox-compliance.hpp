#ifndef VENTILATOR_SPINBOX_COMPLIANCE_HPP__
#define VENTILATOR_SPINBOX_COMPLIANCE_HPP__

#include <QDoubleValidator>
#include <QDoubleSpinBox>
#include <ventilation/ventilation.hpp>

namespace ventilator {
namespace spinbox {
    class Compliance : public QDoubleSpinBox {
        Q_OBJECT
        public:
            Compliance(QWidget * parent = nullptr);
            ~Compliance();
        signals:
            void compliance(ventilation::Compliance<double>) const;
        private slots:
            void update(double);
        private:
            QDoubleValidator *  validator_;
    };
} // namespace spinbox
} // namespace ventilator

#endif // VENTILATOR_SPINBOX_COMPLIANCE_HPP__
