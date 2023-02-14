#include "main.h"

// Helper functions
void setIntake(int power) {
    intake = power;
}

// Intake control functions
void setIntakeMotor() {
    // L2 forward, L1 reverse
    int intakePower = 127 * (controller1.getDigital(ControllerDigital::R1) - controller1.getDigital(ControllerDigital::L1));
    setIntake(intakePower);
}
