#pragma once

#include "chrono/assets/ChVisualShapeTriangleMesh.h"

#include "chrono_vehicle/ChSubsysDefs.h"
#include "chrono_vehicle/ChVehicleDataPath.h"
#include "chrono_vehicle/wheeled_vehicle/ChWheel.h"

namespace chrono {
namespace vehicle {
namespace grcorolla {

class GRCorolla_Wheel : public ChWheel {
public:
    GRCorolla_Wheel(const std::string& name);
    ~GRCorolla_Wheel();

    virtual double GetWheelMass() const override { return m_mass; }
    virtual double GetRadius() const override { return radius; }
    virtual double GetWidth() const override { return width; }

    virtual const ChVector3d& GetWheelInertia() const override { return inertia; }

protected:
    static const double radius;
    static const double width;
    static const ChVector3d inertia;
};

}
}
}

