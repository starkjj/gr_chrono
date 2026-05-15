#pragma once

#include "chrono_vehicle/wheeled_vehicle/brake/ChBrakeSimple.h"

namespace chrono {
namespace vehicle {
namespace grcorolla {

class GRCorolla_BrakeSimple : public ChBrakeSimple {
public:
    GRCorolla_BrakeSimple(const std::string& name);
    virtual ~GRCorolla_BrakeSimple();

    virtual double GetMaxBrakingTorque() override { return maxTorque; }

private:
    static const double maxTorque;
};

}
}
}

