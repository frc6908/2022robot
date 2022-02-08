// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <ctre/phoenix/motorcontrol/FeedbackDevice.h>
#include <ctre/phoenix/motorcontrol/NeutralMode.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>

#include <frc/MotorControllerGroup.h>

#include <AHRS.h>

#include <CANVenom.h>

#include <frc/SpeedControllerGroup.h>
#include <frc/SPI.h>


#include <frc/drive/DifferentialDrive.h>

#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Rotation2d.h>

#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>

#include <units/angle.h>

#include <Constants.h>

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain() {
    rightMotors.SetInverted(1);

    resetEncoders();
    resetGyro();
  }

  void setDriveMotors(double left, double right) {
    if (flipped) {
      leftMotors.Set(-right);
      rightMotors.Set(-left);
    } else {
      leftMotors.Set(left);
      rightMotors.Set(right);
    }
  }

  void arcadeDrive(double throttle, double turn) {
    setDriveMotors(throttle + turn, throttle - turn);
  }

  frc::Rotation2d getHeading() {
    return frc::Rotation2d(units::degree_t{-gyro.getAngle()});
  }

  double getHeadingAsAngle() {
    return getHeading().Degrees();
  }

  void stop() {
    leftMotors.Set(0);
    rightMotors.Set(0);
  }

  void resetEncoders() {
    leftDriveVenom.ResetPosition();
    rightDriveVenom.ResetPosition();
  }
  double getLeftEncoderDistance() {
    return leftDriveVenom.GetPosition();
  }

  double getRightEncoderDistance() {
    return rightDriveVenom.GetPosition();
  }

  void flipDT() {
    flipped = !flipped;
  }

  void resetGyro() {
    gyro.reset();
  }

  void resetPose(frc::Pose2d poseMeters) {
    odometry.ResetPosition(poseMeters, getHeading()); 
  }

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX leftDriveTalon{0};
  frc::CANVenom leftDriveVenom{0};

  ctre::phoenix::motorcontrol::can::WPI_TalonSRX rightDriveTalon{0};
  frc::CANVenom rightDriveVenom{0}; 

  frc::SpeedControllerGroup leftMotors{leftDriveTalon, leftDriveVenom};
  frc::SpeedControllerGroup rightMotors{rightDriveTalon, rightDriveVenom};

  frc::MotorControllerGroup leftMotors{leftDriveTalon, leftDriveVenom};
  frc::MotorControllerGroup rightMotors{rightDriveTalon, rightDriveVenom};

  rightMotors.setInverted(true);

  frc::AHRS gryo{0};
  frc::DifferentialDriveOdometry odometry;
  frc::DifferentialDrive drive{leftMotors, rightMotors};

  bool flipped = 0;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
