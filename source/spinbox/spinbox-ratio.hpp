#ifndef VENTILATOR_SPINBOX_RATIO_HPP__
#define VENTILATOR_SPINBOX_RATIO_HPP__

#include <QIntValidator>
#include <QSpinBox>
#include <ventilation/ventilation.hpp>

namespace ventilator {
namespace spinbox {
    class Expiration : public QSpinBox {
        Q_OBJECT
        public:
            Expiration(QWidget * parent = nullptr);
            ~Expiration();
        signals:
            void expiration(int) const;
        private:
            QIntValidator *  validator_;
    };

    class Inspiration : public QSpinBox {
        Q_OBJECT
        public:
            Inspiration(QWidget * parent = nullptr);
            ~Inspiration();
        signals:
            void inspiration(int) const;
        private:
            QIntValidator *  validator_;
    };

    class Ratio : public QWidget {
        Q_OBJECT
        public:
            Ratio(QWidget * parent = nullptr);
            ~Ratio();

            ventilation::ratio::Ratio<double> get() const;
        signals:
            void ratio(const ventilation::ratio::Ratio<double>& r);
        private slots:
            void inspiration(int);
            void expiration(int);
        private:
            Inspiration *   inspiration_;
            Expiration *    expiration_;
    };
} // namespace spinbox
} // namespace ventilator

#endif // VENTILATOR_SPINBOX_RATIO_HPP__
