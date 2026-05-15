#pragma once

#include <array>
#include <string>

#include "chrono_vehicle/wheeled_vehicle/ChTire.h"
#include "GRCorolla_Vehicle.h"
#include "chrono_models/vehicle/ChVehicleModelDefs.h"

namespace chrono {
namespace vehicle {
namespace grcorolla {

// Definition of the GR Corolla assembly
class GRCorolla {
public:
    virtual ~GRCorolla();

    auto SetContactMethod(ChContactMethod val) -> void { contactMethod = val; }
    auto SetCollisionSystemType(ChCollisionSystem::Type type) -> void { collisionSystemType = type; }

    auto SetChassisFixed(bool val) -> void { fixed = val; }
    auto SetChassisCollisionType(CollisionType type) -> void { chassisCollisionType = type; }

    auto SetSteeringType(SteeringTypeWV val) -> void { steeringType = val; }
    auto SetDriveType(DrivelineTypeWV val) -> void { driveType = val; }
    auto SetBrakeType(BrakeType val) -> void { brakeType = val; }
    auto SetEngineType(EngineModelType val) -> void { engineType = val; }
    auto SetTransmissionType(TransmissionModelType val) -> void { transmissionType = val; }
    auto SetTireType(TireModelType val) -> void { tireType = val; }

    auto SetTireCollisionType(ChTire::CollisionType val) -> void { tireCollisionType = val; }
    auto SetTireContactSurfaceType(ChTire::ContactSurfaceType surfaceType, double surfaceDim, int collisionFamily) -> void;

    auto SetInitPosition(const ChCoordsys<>& pos) -> void { initPos = pos; }
    auto SetInitFwdvel(double vel) -> void { initFwdVel = vel; }
    auto SetInitWheelAngVel(const std::vector<double>& omega) -> void { initOmega = omega; }

    auto SetTireStepSize(double stepSize) -> void { tireStepSize = stepSize; }

    auto SetChassisCollisionGeometry(const utils::ChBodyGeometry& geom) -> void { chassisCollisionGeometry = geom; }

    auto EnableBrakeLocking(bool val) -> void { brakeLocking = val; }

    auto GetSystem() -> ChSystem* { return vehicle->GetSystem(); }
    auto GetVehicle() -> ChWheeledVehicle& { return *vehicle; }
    auto GetChassis() const -> std::shared_ptr<ChChassis> { return vehicle->GetChassis(); }
    auto GetChassisBody() const -> std::shared_ptr<ChBodyAuxRef> { return vehicle->GetChassisBody(); }
    auto GetRefFrame() const -> const ChFrameMoving<>& { return vehicle->GetRefFrame(); }

    auto Initialize() -> void;

    auto SetAerodynamicDrag(double Cd, double area, double airDensity) -> void;

    auto SetChassisVisualizationType(VisualizationType vis) -> void { vehicle->SetChassisVisualizationType(vis); }
    auto SetSuspensionVisualizationType(VisualizationType vis) -> void { vehicle->SetSuspensionVisualizationType(vis); }
    auto SetSteeringVisualizationType(VisualizationType vis) -> void { vehicle->SetSteeringVisualizationType(vis); }
    auto SetWheelVisualizationType(VisualizationType vis) -> void { vehicle->SetWheelVisualizationType(vis); }
    auto SetTireVisualizationType(VisualizationType vis) -> void { vehicle->SetTireVisualizationType(vis); }

    auto Synchronize(double time, const DriverInputs& driveInputs, const ChTerrain& terrain) -> void;
    auto Advance(double step) -> void;

protected:
    // protected constructors -- this class cannot be instantiated by itself.
    GRCorolla();
    GRCorolla(ChSystem* system);

    virtual GRCorolla_Vehicle* CreateVehicle() = 0;

    ChContactMethod contactMethod{};
    ChCollisionSystem::Type collisionSystemType{};
    CollisionType chassisCollisionType{};
    utils::ChBodyGeometry chassisCollisionGeometry{};
    bool fixed{};
    bool brakeLocking{};

    SteeringTypeWV steeringType{};
    DrivelineTypeWV driveType{};
    EngineModelType engineType{};
    TransmissionModelType transmissionType{};
    BrakeType brakeType{};
    TireModelType tireType{};
    ChTire::CollisionType tireCollisionType{};
    ChTire::ContactSurfaceType contactSurfaceType{};
    double tireSurfaceDim{};
    int tireCollisionFamily{};

    double tireStepSize{};

    ChCoordsys<> initPos{};
    double initFwdVel{};
    std::vector<double> initOmega{};

    bool applyDrag{};
    double Cd{};
    double area{};
    double airDensity{};

    ChSystem* system{};
    GRCorolla_Vehicle* vehicle{};

    double tireMass{};
};

}
}
}

