#ifndef VENTILATOR_LUNG_RESISTANCE_HPP__
#define VENTILATOR_LUNG_RESISTANCE_HPP__

#include <QDoubleValidator>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QWidget>
#include <ventilation/ventilation.hpp>

namespace ventilator {
namespace lung {
    class Resistance : public QWidget {
        Q_OBJECT
        public:
            Resistance(QWidget * parent = nullptr);
            ~Resistance();
        signals:
            void resistance(ventilation::Resistance<double>) const;
        private slots:
            void update(double);
        private:
            QDoubleSpinBox *    values_;
            QDoubleValidator *  validator_;
    };
} // namespace lung
} // namespace ventilator

#endif // VENTILATOR_LUNG_RESISTANCE_HPP__
