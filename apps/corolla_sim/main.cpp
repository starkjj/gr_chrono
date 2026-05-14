#include <chrono/physics/ChSystemNSC.h>
#include <chrono/physics/ChBodyEasy.h>
#include <chrono/physics/ChLinkMate.h>
#include <chrono/assets/ChTexture.h>
#include <chrono/core/ChRealtimeStep.h>
#include <chrono_vsg/ChVisualSystemVSG.h>

// Use the namespaces of Chrono
using namespace chrono;
using namespace chrono::vsg3d;

int main(int argc, char* argv[]) {
    // Set path to Chrono data directory
    SetChronoDataPath(CHRONO_DATA_DIR);

    // 0 - Create a Chrono physical system
    ChSystemNSC sys;
    sys.SetGravitationalAcceleration(ChVector3d(0, -9.81, 0));
    sys.SetCollisionSystemType(ChCollisionSystem::Type::BULLET);

    // 1 - Create a fixed floor body (also used to represent the absolute reference)
    auto floor_body = std::make_shared<ChBodyEasyBox>(10, 2, 10,  // x, y, z dimensions
                                                      3000,       // density
                                                      true,       // create visualization asset
                                                      false       // no collision geometry
    );
    floor_body->SetFixed(true);
    floor_body->SetPos(ChVector3d(0, -2, 0));
    floor_body->GetVisualShape(0)->SetTexture(GetChronoDataFile("textures/checker1.png"), 2,
                                              2);  // optionally set color and/or texture for visual assets
    sys.Add(floor_body);

    // 2 - Create a pendulum body
    auto pendulum_body = std::make_shared<ChBodyEasyBox>(0.5, 2, 0.5,  // x, y, z dimensions
                                                         3000,         // density
                                                         true,         // create visualization asset
                                                         false         // no collision geometry
    );
    pendulum_body->SetPos(ChVector3d(0, 3, 0));
    pendulum_body->SetLinVel(ChVector3d(1, 0, 0));
    pendulum_body->GetVisualShape(0)->SetColor(ChColor(0.2f, 0.5f, 0.25f));
    sys.Add(pendulum_body);

    // 3 - Create a spherical constraint
    //     Here we use a ChLinkMateGeneric, but we could also create a ready-to-use ChLinkMateSpherical
    auto sperical_link =
        std::make_shared<ChLinkMateGeneric>(true, true, true, false, false, false);  // x, y, z, Rx, Ry, Rz constrains
    ChFrame<> link_position_abs(ChVector3d(0, 4, 0));
    sperical_link->Initialize(pendulum_body,      // the 1st body to connect
                              floor_body,         // the 2nd body to connect
                              false,              // the two following frames are in absolute, not relative, coordinates
                              link_position_abs,  // the link reference attached to 1st body
                              link_position_abs);  // the link reference attached to 2nd body
    sys.Add(sperical_link);

    // 4 - Create the VSG visualization system
    auto vis = chrono_types::make_shared<ChVisualSystemVSG>();
    vis->AttachSystem(&sys);
    vis->SetCameraVertical(CameraVerticalDir::Z);
    vis->SetWindowSize(ChVector2i(1200, 800));
    vis->SetWindowPosition(ChVector2i(100, 300));
    vis->SetWindowTitle("Chrono VSG Assets");
    vis->AddCamera(ChVector3d(8.0, 12.3, 3.0), ChVector3d(-0.1, 1.0, 0.4));
    vis->SetCameraAngleDeg(40);
    vis->SetLightIntensity(1.0f);
    vis->SetLightDirection(CH_PI_2, CH_PI_4);



    // 5 - Simulation loop
    ChRealtimeStepTimer realtime_timer;
    double timestep = 5e-3;

    // Optionally customize solver settings
    sys.SetSolverType(ChSolver::Type::PSOR);
    sys.GetSolver()->AsIterative()->SetMaxIterations(100);
    sys.GetSolver()->AsIterative()->SetTolerance(1e-6);

    vis->Initialize();

    while (vis->Run()) {
        // Render scene
        vis->Render();

        // Perform the time integration step
        sys.DoStepDynamics(timestep);

        // Spin in place to maintain soft real-time
        realtime_timer.Spin(timestep);
    }

    return 0;
}