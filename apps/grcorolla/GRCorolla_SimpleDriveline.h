#pragma once
#include "chrono_vehicle/wheeled_vehicle/driveline/ChSimpleDriveline.h"

namespace chrono {
namespace vehicle {
namespace grcorolla {

// Simple driveline for now, will add a shafts based one later
class GRCorolla_SimpleDriveline : public ChSimpleDriveline {
public:
    GRCorolla_SimpleDriveline(const std::string& name);
    ~GRCorolla_SimpleDriveline();

    virtual double GetFrontTorqueFraction() const override { return frontTorqueFrac; }
    virtual double GetFrontDifferentialMaxBias() const override { return frontDiffBias; }
    virtual double GetRearDifferentialMaxBias() const override { return rearDiffBias; }

    virtual double GetFrontConicalGearRatio() const override { return frontConicalgearRatio; }
    virtual double GetRearConicalGearRatio() const override { return rearConicalgearRatio; }

private:
    static const double frontTorqueFrac;
    static const double frontDiffBias;
    static const double rearDiffBias;
    static const double frontConicalgearRatio;
    static const double rearConicalgearRatio;
};

}
}
}