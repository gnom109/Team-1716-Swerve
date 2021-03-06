// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DriveTrain: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	static const double pi=3.14159;

	float gyroreference;

	bool GyroZeroFlag;
	float GyroZeroTime;

	//Steering Functions
	void LeftTurn4Wheels();	//Calculates a left hand turn
	void RightTurn4Wheels();	//Calculates a right hand turn


	//DriveDirection
	bool driveFront;

	//Steering Variables
	double radian; // input steering angle in radians
	double A;	//A is the ratio of X to turn harder
	double W;	//W is the distance form the mid-point of one back wheel to the mid-point of the other back wheel
	double X;	//X is the distance form the mid-point of the back wheels to the mid-point of the front wheels
	double Y;	//Y is the distance from the mid-point of one front wheel to the mid-point of the other front wheel

	double FL;	//FL, distance from Front Left Wheel to the center of rotation
	double FR;	//FR, distance from Front Right Wheel to the center of rotation
	double RL;	//RL, distance from Rear Left Wheel to the center of rotation
	double RR;	//RR, distance from Rear Right Wheel to the center of rotation

	double Z;	//Z, distance form A * X to center of rotation

	double thetaRC;	//Angle used to calculate all other angles

	double thetaFL;	//thetaFL, angle from Front Left Wheel to the center of rotation
	double thetaFR;	//thetaFR, angle from Front Right Wheel to the center of rotation
	double thetaRL;	//thetaRL, angle from Rear Left Wheel to the center of rotation
	double thetaRR;	//thetaRR, angle from Rear Right Wheel to the center of rotation
	double FRRatio;	//Ratio of Speed of Front Right wheel
	double FLRatio;	//Ratio of Speed of Front Left wheel
	double RRRatio;	//Ratio of Speed of Rear Right wheel
	double RLRatio;	//Ratio of Speed of Rear Left wheel

	double FLOffset;
	double FROffset;
	double RLOffset;
	double RROffset;

	//Crab Variables
	double AP;
	double BP;
	double CP;
	double DP;
	double radius; //distance from center to each wheel
	double robotangle; //current robot angle from Gyro

	//Inversion Variables
	int FLInv;
	int FRInv;
	int RLInv;
	int RRInv;

	double CorrectSteerSetpoint(double setpoint);
	void SetSteerSetpoint(float FLSetPoint, float FRSetPoint, float RLSetPoint, float RRSetPoint);
	void SetDriveSpeed(float FLSpeed, float FRSpeed, float RLSpeed, float RRSpeed);

public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	AnalogInput* frontRightPos;
	SpeedController* frontRightSteer;
	PIDController* frontRight;
	AnalogInput* frontLeftPos;
	SpeedController* frontLeftSteer;
	PIDController* frontLeft;
	AnalogInput* rearRightPos;
	SpeedController* rearRightSteer;
	PIDController* rearRight;
	AnalogInput* rearLeftPos;
	SpeedController* rearLeftSteer;
	PIDController* rearLeft;
	SpeedController* frontRightDrive;
	SpeedController* frontLeftDrive;
	SpeedController* rearRightDrive;
	SpeedController* rearLeftDrive;
	Gyro* gyro;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	DriveTrain();
	void InitDefaultCommand();

	void SetWheelbase(float w, float x, float y);
	void SetOffsets(double FLOff, double FROff, double RLOff, double RROff);
	void ToggleFrontBack();
	void Steer(float radian, float speed, float a);
	void Crab(float twist, float y, float x, bool UseGyro);
	bool ZeroGyro(float InitTime);
	void Lock();
	void SideLock();
};

#endif
