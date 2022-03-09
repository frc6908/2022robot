// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <rev/CANSparkMax.h>
#include <rev/CANSparkMaxLowLevel.h>


#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>

#include "Constants.h"


class Shooter: public frc2::SubsystemBase {
 public:
  Shooter();

  void setBottomMotorVoltage(units::voltage::volt_t);

  void setTopMotorVoltage(units::voltage::volt_t);

  void stopShooter();



  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  
  rev::CANSparkMax bottomSpark{shooter::kBottomSparkPort, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::CANSparkMax topSpark{shooter::kTopSparkPort, rev::CANSparkMaxLowLevel::MotorType::kBrushless};

  frc::ShuffleboardTab& tab = frc::Shuffleboard::GetTab("Test");
};
