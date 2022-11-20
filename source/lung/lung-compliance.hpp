#ifndef VENTILATOR_LUNG_COMPLIANCE_HPP__
#define VENTILATOR_LUNG_COMPLIANCE_HPP__

#include <QDoubleValidator>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QWidget>
#include <ventilation/ventilation.hpp>

namespace ventilator {
namespace lung {
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
} // namespace lung
} // namespace ventilator

#endif // VENTILATOR_LUNG_COMPLIANCE_HPP__
