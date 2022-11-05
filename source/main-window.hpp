#ifndef VENTILATIOR_WINDOW_HPP__
#define VENTILATIOR_WINDOW_HPP__


#include <QChart>
#include <QLineSeries>
#include <QMainWindow>
#include <QPointF>
#include <QVector>

class Widget : public QWidget {
    Q_OBJECT
    public:
        Widget(QWidget * parent = 0);
        ~Widget();
    public slots:
        void update();
    private:
        QChart *            chart_;
        QLineSeries *       series_;
        QVector<QPointF>    ps_;

        std::size_t counter_;
};

class Ventilator : public QMainWindow {
    Q_OBJECT
    public:
        Ventilator(QWidget * parent = 0);
        ~Ventilator();
    private:
        Widget * widget_;
};

#endif // VENTILATIOR_WINDOW_HPP__
