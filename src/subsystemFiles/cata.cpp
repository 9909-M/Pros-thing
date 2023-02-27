#include "main.h"

// Helper functions
void setCata(int power) {
    cata = power;
}

// Cata control functions
void setCataMotor() {
    // R2 forward, R1 reverse
    int cataPower = 127 * (controller1.getDigital(ControllerDigital::R1) - controller1.getDigital(ControllerDigital::R2));
    setCata(cataPower);
}
