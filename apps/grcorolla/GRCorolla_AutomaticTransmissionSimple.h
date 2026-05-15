#pragma once

#include "chrono_vehicle/powertrain/ChAutomaticTransmissionSimpleMap.h"

namespace chrono {
namespace vehicle {
namespace grcorolla {

class GRCorolla_AutomaticTransmissionSimple {
public:
    GRCorolla_AutomaticTransmissionSimple(const std::string& name);
    ~GRCorolla_AutomaticTransmissionSimple();

    // set the transmission gear ratios
    virtual void SetGearRatios(std::vector<double>& fwd, double& rev) override;

    // set the ideal shift points for automatic gear shifting/
    // For each forward gear, we specify the min and max engine speed for shifting up and down
    virtual void SetShiftPoints(std::vector<std::pair<double, double>>& shift_bands) override;
};

}
}
}