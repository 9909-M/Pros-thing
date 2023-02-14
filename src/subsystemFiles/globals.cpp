#include "main.h"
#include "pros/adi.h"

// Controllers
okapi::Controller controller1(ControllerId::master);

// Motors
pros::Motor driveLeftFront(1, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLeftCenter(2, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLeftBack(3, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightFront(4, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightCenter(5, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightBack(6, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intake(11, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);

// Motor Groups
pros::Motor_Group driveLeft({driveLeftBack, driveLeftCenter, driveLeftFront});
pros::Motor_Group driveRight({driveRightBack, driveRightCenter, driveRightFront});

// ADI Digital Outs
pros::ADIDigitalOut stringLauncher1('H', false);

// Inertial Sensor
pros::Imu imu(20);

// Chassis controller
std::shared_ptr<okapi::OdomChassisController> chassis =
	ChassisControllerBuilder()
		.withMotors({1, 2, 3}, {4, 5, 6})
		// Green gearset, 2.75" wheel diameter, 11.75" wheel track, 10.75" wheelbase, gear ratio 72:36
		.withDimensions({AbstractMotor::gearset::green, (72.0 / 36.0)}, {{2.75_in, 11.75_in}, imev5GreenTPR})
		.withGains(
			{0.001, 0, 0.0001},	// Distance controller gains
			{0.001, 0, 0.0001},	// Turn controller gains
			{0.001, 0, 0.0001})	// Angle controller gains
		.withOdometry() // Use the same scales as the chassis (above) for odometry (not worth it without encoders & tracking wheel)
        .withMaxVelocity(160)
		.buildOdometry();
