#ifndef VENTILATOR_SPINBOX_FREQUENCY_HPP__
#define VENTILATOR_SPINBOX_FREQUENCY_HPP__

#include <QIntValidator>
#include <QSpinBox>
#include <ventilation/ventilation.hpp>

namespace ventilator {
namespace spinbox {
    class Frequency : public QSpinBox {
        Q_OBJECT
        public:
            Frequency(const double& f, QWidget * parent = nullptr);
            Frequency(const ventilation::frequency::Frequency<double>& f, QWidget * parent = nullptr);
            Frequency(QWidget * parent = nullptr);
            ~Frequency();

            ventilation::frequency::Frequency<double> get() const;
        signals:
            void frequency(ventilation::frequency::Frequency<double>) const;
        private slots:
            void update(int);
        private:
            QIntValidator *  validator_;
    };
} // namespace spinbox
} // namespace ventilator

#endif // VENTILATOR_SPINBOX_FREQUENCY_HPP__
