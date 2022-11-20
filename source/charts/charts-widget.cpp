#include "charts-widget.hpp"

#include <QVBoxLayout>

namespace ventilator {
namespace charts {
    Charts::Charts(QWidget * parent)
        : QFrame(parent)
    {
        flow_ = new Chart;
        pressure_ = new Chart;
        volume_ = new Chart;

        flow_->set_title("Flow (L/s)");
        pressure_->set_title("Pressure (cmH<sub>2</sub>O)");
        volume_->set_title("Volume (L)");

        QVBoxLayout * layout = new QVBoxLayout;
        layout->addWidget(flow_);
        layout->addWidget(pressure_);
        layout->addWidget(volume_);
        setLayout(layout);
    }

    void
    Charts::update(const ventilation::Packet<double>& p) {
        flow_->update(p.flow);
        pressure_->update(p.pressure);
        volume_->update(p.volume);
    }

    Charts::~Charts() {}
} // namespace charts
} // namespace ventilator
