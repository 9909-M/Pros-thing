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
pros::Motor intake(10, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor cata(9, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);

// Motor Groups
pros::Motor_Group driveLeft({driveLeftBack, driveLeftCenter, driveLeftFront});
pros::Motor_Group driveRight({driveRightBack, driveRightCenter, driveRightFront});

// ADI Digital Outs
pros::ADIDigitalOut stringLauncher1('H', false);

// Inertial Sensor
pros::Imu imu(8);

// Chassis controller
std::shared_ptr<okapi::OdomChassisController> chassis =
	ChassisControllerBuilder()
		.withMotors({1, 2, 3}, {4, 5, 6})
		// Green gearset, 2.75" wheel diameter, 11.75" wheel track, 10.75" wheelbase, gear ratio 72:36
		.withDimensions({AbstractMotor::gearset::green, (36.0 / 72.0)}, {{3.25_in, 11.75_in}, imev5GreenTPR})
		.withGains(
			{0.003, 0, 0.0002},	// Distance controller gains   change when have catapult
			{0.004, 0, 0.00007},	// Turn controller gains   good enough, fine tune when have time
			{0.001, 0, 0.0000})	// Angle controller gains
		.withOdometry() // Use the same scales as the chassis (above) for odometry (not worth it without encoders & tracking wheel)
        .withMaxVelocity(160)
		.buildOdometry();
