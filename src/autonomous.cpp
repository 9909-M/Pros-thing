#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    // Display gif image on the brain screen
    //static Gif gif("/usd/logo_unstretched.gif", lv_scr_act());

    if (selector::auton == 1 || selector::auton == -1) {        // Left side auton
        // Set the odometric state to zero
        chassis->setState({0_in, 0_in, 0_deg});

        // Step 1
        chassis->driveToPoint({48_in, 0_in});
    }

    else if (selector::auton == 2 || selector::auton == -2) {   // Right side match auton
        // Set the odometric state to zero
        chassis->setState({0_in, 0_in, 0_deg});

        // Step 1
        chassis->turnToAngle(90_deg);
    }

    else if (selector::auton == 0) {
        // Set the odometric state to zero
        chassis->setState({0_in, 0_in, 0_deg});

        // Step 1
        chassis->driveToPoint({1_in, 0_in});
    }
}
