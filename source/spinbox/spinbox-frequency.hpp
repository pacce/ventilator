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
            Frequency(QWidget * parent = nullptr);
            ~Frequency();
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
