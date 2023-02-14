#include "main.h"
#include "pros/misc.h"

bool launchString = true

// String launcher control functions
void setStringLaunchers() {
    if (controller1.getDigital(ControllerDigital::A)) {
        if (launchString) {
            stringLauncher1.setValue(1);
            //stringLauncher2.setValue(1);
            launchString = false;
            pros::delay(500);
        }
        else {
            stringLauncher1.setValue(1);
            //stringLauncher2.setValue(1);
            launchString = true;
            pros::delay(500);
        }
    }
}
