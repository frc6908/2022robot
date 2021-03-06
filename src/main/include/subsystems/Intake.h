// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>

#include "Constants.h"


class Intake: public frc2::SubsystemBase {
 public:
  Intake();

  void setIntakeMotor(double);

  void setBottomFeederMotor(double);

  void stopIntake();

  void stopBottomFeeder();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  ctre::phoenix::motorcontrol::can::WPI_TalonSRX IntakeVictor{intake::kIntakeTalonPort};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX BottomFeederVictor{intake::kBottomFeederVictorPort};

};
