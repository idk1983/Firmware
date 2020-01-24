//
// Multicopter mission test.
//
// Author: Julian Oes <julian@oes.ch>

#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/action/action.h>
#include <mavsdk/plugins/telemetry/telemetry.h>
#include <iostream>
#include <string>
#include "autopilot_tester.h"


TEST_CASE("Takeoff and Land (Multicopter with optical flow)", "[multicopter_opt_flow]")
{
    AutopilotTester tester;
    tester.connect(connection_url);
    tester.wait_until_ready_local_position_only();
    tester.arm();
    tester.offboard_position_takeoff();
    tester.wait_until_hovering();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    tester.offboard_position_land();
    tester.wait_until_disarmed();
}
