#pragma once

#include "chrono_vehicle/wheeled_vehicle/tire/ChTMeasyTire.h"

namespace chrono {
namespace vehicle {
namespace grcorolla {

class GRCorolla_TMeasyTire : public ChTMeasyTire{
public:
    GRCorolla_TMeasyTire(const std::string& name);
    ~GRCorolla_TMeasyTire() {};

    virtual double GetVisualizationWidth() const override { return m_width; }

    virtual void SetTMeasyParams() override;
    virtual double GetTireMass() const override { return m_mass; }
    virtual ChVector3d GetTireInertia() const override { return m_inertia; }

    virtual void AddVisualizationAssets(VisualizationType vis) override;
    virtual void RemoveVisualizationAssets() override final;

    void GenerateCharacteristicPlots(const std::string& dirname);

private:
    static const double mass;
    static const ChVector3d inertia;

    ChFunctionInterp stiffnessMap;

    static const std::string meshFileLeft;
    static const std::string meshFileRight;
    std::shared_ptr<ChVisualShapeTriangleMesh> trimeshShape;
};

}
}
}