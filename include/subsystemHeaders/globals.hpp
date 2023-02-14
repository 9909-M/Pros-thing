#include "main.h"
#include "pros/adi.hpp"

// Controller
extern okapi::Controller controller1;

// Motors
extern pros::Motor driveLeftFront;
extern pros::Motor driveLeftCenter;
extern pros::Motor driveLeftBack;
extern pros::Motor driveRightFront;
extern pros::Motor driveRightCenter;
extern pros::Motor driveRightBack;
extern pros::Motor intake;

// Motor Group
extern pros::Motor_Group driveLeft;
extern pros::Motor_Group driveRight;

// ADI Digital Outs
extern pros::ADIDigitalOut stringLauncher1;

// Intertial Sensor
extern pros::Imu imu;

// OkapiLib's ChassisController
extern std::shared_ptr<okapi::OdomChassisController> chassis;
