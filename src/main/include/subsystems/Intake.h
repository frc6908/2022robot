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

  void setActuateMotor(double);

  void setIntakeMotor(double);

  void stop();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  ctre::phoenix::motorcontrol::can::WPI_TalonSRX ActuateTalon{intake::kActuateTalonPort};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX IntakeVictor{intake::kIntakeVictorPort};


  frc::ShuffleboardTab& tab = frc::Shuffleboard::GetTab("Test");
};
