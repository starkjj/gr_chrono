#pragma once

#include "chrono_vehicle/chassis/ChRigidChassis.h"
#include "chrono_models/vehicle/ChVehicleModelDefs.h"

namespace chrono {
namespace vehicle {
namespace grcorolla {

// GR Corolla subsystem
class GRCorolla_Chassis : ChRigidChassis {
public:
    GRCorolla_Chassis(const std::string& name,
                  bool fixed = false,
                  CollisionType chassis_collision_type = CollisionType::NONE);

    ~GRCorolla_Chassis();

    // Get the local driver position and orientation
    // This is a coordinate system relative to the chassis reference frame.
    virtual ChCoordsys<> GetLocalDriverCoordsys() const override { return driverCsys; }

protected:
    virtual double GetBodyMass() const override { return bodyMass; }
    virtual ChMatrix33<> GetBodyInertia() const override { return bodyInertia; }
    virtual ChFrame<> GetBodyCOMFrame() const override { return ChFrame<>(bodyComLoc, QUNIT); }

    ChMatrix33<> bodyInertia{};

    static const double bodyMass;
    static const ChVector3d bodyInertiaXX;
    static const ChVector3d bodyInertiaXY;
    static const ChVector3d bodyComLoc;
    static const ChCoordsys<> driverCsys;
};

}
}
}

