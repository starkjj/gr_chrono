#pragma once
#include "chrono_vehicle/wheeled_vehicle/steering/ChRackPinion.h"

namespace chrono {
namespace vehicle {
namespace grcorolla {

class GRCorolla_RackPinion : public ChRackPinion {
public:
    GRCorolla_RackPinion(const std::string& name);
    ~GRCorolla_RackPinion() {}

    virtual double GetSteeringLinkMass() const override { return steeringLinkMass; }
    virtual ChVector3d GetSteeringLinkInertia() const override { return steeringLinkInertia; }
    virtual double GetSteeringLinkCOM() const override { return steeringLinkCOM; }
    virtual double GetSteeringLinkRadius() const override { return steeringLinkRadius; }
    virtual double GetSteeringLinkLength() const override { return steeringLinkLength; }

    virtual double GetPinionRadius() const override { return pinionRadius; }

    virtual double GetMaxAngle() const override { return maxAngle; }

private:
    static const double steeringLinkMass;
    static const ChVector3d steeringLinkInertia;
    static const double steeringLinkCOM;
    static const double steeringLinkRadius;
    static const double steeringLinkLength;

    static const double pinionRadius;

    static const double maxAngle;
};

}
}
}

