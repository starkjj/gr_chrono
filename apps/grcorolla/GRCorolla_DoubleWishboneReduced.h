#pragma once

#include "chrono_vehicle/wheeled_vehicle/suspension/ChDoubleWishboneReduced.h"

namespace chrono {
namespace vehicle {
namespace grcorolla {


// Reduced double wishbone rear suspension for the GR Corolla
// the control arms are modeled using distance constraints
// Note to self: I want to model the full version at some point...
class GRCorolla_DoubleWishboneReducedFront : public ChDoubleWishboneReduced {
public:
    GRCorolla_DoubleWishboneReducedFront(const std::string& name);
    ~GRCorolla_DoubleWishboneReducedFront();

    virtual double getCamberAngle() const override { return 0; }
    virtual double getToeAngle() const override { return 0; }

    virtual double getSpindleMass() const override { return spindleMass; }
    virtual double getUprightMass() const override { return uprightMass; }

    virtual double getSpindleRadius() const override { return spindleRadius; }
    virtual double getSpindleWidth() const override { return spindleWidth; }
    virtual double getUprightRadius() const override { return uprightRadius; }

    virtual const ChVector3d& getSpindleInertia() const override { return spindleInertia; }
    virtual const ChVector3d& getUprightInertia() const override { return uprightInertia; }

    virtual double getAxleInertia() const override { return axleInertia; }

    virtual double getSpringRestLength() const override { return springRestLength; }
    virtual std::shared_ptr<ChLinkTSDA::ForceFunctor> getShockForceFunctor() const override { return shockForceCB; }

private:
    virtual const ChVector3d getLocation(PointId which) override;

    std::shared_ptr<ChLinkTSDA::ForceFunctor> shockForceCB;

    static const double spindleMass;
    static const double uprightMass;

    static const double spindleRadius;
    static const double spindleWidth;
    static const double uprightRadius;

    static const ChVector3d spindleInertia;
    static const ChVector3d uprightInertia;

    static const double axleInertia;

    static const double springCoefficient;
    static const double dampingCoefficient;
    static const double springRestLength;
};

class GRCorolla_DoubleWishboneReducedRear : public ChDoubleWishboneReduced {
public:
    GRCorolla_DoubleWishboneReducedRear(const std::string& name);
    ~GRCorolla_DoubleWishboneReducedRear();

    virtual double getCamberAngle() const override { return 0; }
    virtual double getToeAngle() const override { return 0; }

    virtual double getSpindleMass() const override { return spindleMass; }
    virtual double getUprightMass() const override { return uprightMass; }

    virtual double getSpindleRadius() const override { return spindleRadius; }
    virtual double getSpindleWidth() const override { return spindleWidth; }
    virtual double getUprightRadius() const override { return uprightRadius; }

    virtual const ChVector3d& getSpindleInertia() const override { return spindleInertia; }
    virtual const ChVector3d& getUprightInertia() const override { return uprightInertia; }

    virtual double getAxleInertia() const override { return axleInertia; }

    virtual double getSpringRestLength() const override { return springRestLength; }
    virtual std::shared_ptr<ChLinkTSDA::ForceFunctor> getShockForceFunctor() const override { return shockForceCB; }

private:
    virtual const ChVector3d getLocation(PointId which) override;

    std::shared_ptr<ChLinkTSDA::ForceFunctor> shockForceCB;

    static const double spindleMass;
    static const double uprightMass;

    static const double spindleRadius;
    static const double spindleWidth;
    static const double uprightRadius;

    static const ChVector3d spindleInertia;
    static const ChVector3d uprightInertia;

    static const double axleInertia;

    static const double springCoefficient;
    static const double dampingCoefficient;
    static const double springRestLength;
};

}
}
}

