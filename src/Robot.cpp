// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
DriveTrain* Robot::driveTrain = 0;
OI* Robot::oi = 0;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	driveTrain = new DriveTrain();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();

	File = RAWCConstants::getInstance();
	Robot::driveTrain->SetWheelbase(9.5, 22, 9.5);
	FLOffset = File->getValueForKey("FLOff");
	FROffset = File->getValueForKey("FROff");
	RLOffset = File->getValueForKey("RLOff");
	RROffset = File->getValueForKey("RROff");
	Robot::driveTrain->SetOffsets(FLOffset, FROffset, RLOffset, RROffset);

	Robot::driveTrain->frontLeftPos->SetAverageBits(256);
	Robot::driveTrain->frontRightPos->SetAverageBits(256);
	Robot::driveTrain->rearLeftPos->SetAverageBits(256);
	Robot::driveTrain->rearRightPos->SetAverageBits(256);

	Robot::driveTrain->frontLeft->Enable();
	Robot::driveTrain->frontRight->Enable();
	Robot::driveTrain->rearLeft->Enable();
	Robot::driveTrain->rearRight->Enable();

	prevTrigger = false;

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand = new AutonomousCommand();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	if(Robot::oi->getRotatJoystick()->GetRawButton(7))
		SMDB();

	Scheduler::GetInstance()->Run();

}

void Robot::AutonomousInit() {
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	if(Robot::oi->getRotatJoystick()->GetRawButton(7))
		SMDB();

	//Resets gyro to zero when crab starts
		if (!prevTrigger && Robot::oi->getTransJoystick()->GetRawButton(1))
			Robot::driveTrain->gyro->Reset();
		prevTrigger = Robot::oi->getTransJoystick()->GetRawButton(1);
		if(Robot::oi->getTransJoystick()->GetRawButton(1))
		{//Crab
			Robot::driveTrain->Crab(Robot::oi->getJoystickTwist(),-Robot::oi->getJoystickY(),Robot::oi->getJoystickX(),true);
		}
		else
		{//Steering
			Robot::driveTrain->Steer(Robot::oi->getScaledJoystickRadians(),Robot::oi->getJoystickMagnitude(),0.5);
		}
}

void Robot::TestPeriodic() {
	lw->Run();
}

void Robot::SMDB() {
	//Joystick Variables
	SmartDashboard::PutNumber("StickMagnitude",Robot::oi->getTransJoystick()->GetMagnitude());
	SmartDashboard::PutNumber("StickDirection",Robot::oi->getTransJoystick()->GetDirectionRadians());
	//SmartDashboard::PutNumber("StickTwist",Robot::oi->getRotatJoystick()->GetTwist());
	SmartDashboard::PutNumber("StickTwist",Robot::oi->getRotatJoystick()->GetY());
	SmartDashboard::PutNumber("GyroAngle", Robot::driveTrain->gyro->GetAngle());
	SmartDashboard::PutNumber("ScaledRadians",Robot::oi->getScaledJoystickRadians());
	//SmartDashboard::PutNumber("ScalingFactor",Robot::oi->getRotatJoystick()->GetTwist()/2+1.5);
	SmartDashboard::PutNumber("ScalingFactor",Robot::oi->getRotatJoystick()->GetY()/2+1.5);
	//Wheel Module Voltages
	SmartDashboard::PutNumber("FrontLeftVol",Robot::driveTrain->frontLeftPos->GetAverageVoltage());
	SmartDashboard::PutNumber("FrontRightVol",Robot::driveTrain->frontRightPos->GetAverageVoltage());
	SmartDashboard::PutNumber("RearLeftVol",Robot::driveTrain->rearLeftPos->GetAverageVoltage());
	SmartDashboard::PutNumber("RearRightVol",Robot::driveTrain->rearRightPos->GetAverageVoltage());
	//Wheel Module Values
	SmartDashboard::PutNumber("FrontLeftValue",Robot::driveTrain->frontLeftPos->GetAverageValue());
	SmartDashboard::PutNumber("FrontRightValue",Robot::driveTrain->frontRightPos->GetAverageValue());
	SmartDashboard::PutNumber("RearLeftValue",Robot::driveTrain->rearLeftPos->GetAverageValue());
	SmartDashboard::PutNumber("RearRightValue",Robot::driveTrain->rearRightPos->GetAverageValue());

	//Wheel Module Errors
	SmartDashboard::PutNumber("FLError", Robot::driveTrain->frontLeft->GetError());
	SmartDashboard::PutNumber("FRError", Robot::driveTrain->frontRight->GetError());
	SmartDashboard::PutNumber("RLError", Robot::driveTrain->rearLeft->GetError());
	SmartDashboard::PutNumber("RRError", Robot::driveTrain->rearRight->GetError());
	//Wheel Module Setpoints
	SmartDashboard::PutNumber("FLSetPoint", Robot::driveTrain->frontLeft->GetSetpoint());
	SmartDashboard::PutNumber("FRSetPoint", Robot::driveTrain->frontRight->GetSetpoint());
	SmartDashboard::PutNumber("RLSetPoint", Robot::driveTrain->rearLeft->GetSetpoint());
	SmartDashboard::PutNumber("RRSetPoint", Robot::driveTrain->rearRight->GetSetpoint());
}
START_ROBOT_CLASS(Robot);

