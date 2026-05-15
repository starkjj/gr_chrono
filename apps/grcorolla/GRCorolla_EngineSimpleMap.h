#pragma once

#include "chrono_vehicle/powertrain/ChEngineSimpleMap.h"

namespace chrono {
namespace vehicle {
namespace grcorolla {

class GRCorolla_EngineSimpleMap : public ChEngineSimpleMap {
public:
    GRCorolla_EngineSimpleMap(const std::string& name);

    // Specify maximum engine speed
    virtual double GetMaxEngineSpeed() override;

    // Set the engine speed-torque maps/
    virtual void SetEngineTorqueMaps(ChFunctionInterp& map0, ChFunctionInterp& mapF) override;
};

}
}
}

