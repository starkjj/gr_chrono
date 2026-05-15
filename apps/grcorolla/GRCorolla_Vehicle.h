#pragma once
#include "chrono_vehicle/wheeled_vehicle/ChWheeledVehicle.h"

namespace chrono {
namespace vehicle {
namespace grcorolla {

class GRCorolla_Vehicle : public ChWheeledVehicle {
public:
    virtual ~GRCorolla_Vehicle();

    virtual unsigned int GetNumberAxles() const override { return 2; }
    virtual double GetWheelbase() const override { return 2.64; }
    virtual double GetMinTurningRadius() const override { return 5.5; }
    virtual double GetMaxSteeringAngle() const override { return 35.0 * CH_DEG_TO_RAD; } // 35-39

    auto SetInitWheelAngVel(const std::vector<double>& w) -> void {
        assert(omega.size() == 4);
        omega = w;
    }

protected:
    GRCorolla_Vehicle(const std::string& name, ChContactMethod contactMethod, DrivelineTypeWV driveType)
        : ChWheeledVehicle(name, contactMethod), driveType(driveType), omega({0, 0, 0, 0}) {}

    GRCorolla_Vehicle(const std::string& name, ChSystem* system, DrivelineTypeWV driveType)
        : ChWheeledVehicle(name, system), driveType(driveType), omega({0, 0, 0, 0}) {}


    DrivelineTypeWV driveType{};
    std::vector<double> omega;
};

}
}
}

