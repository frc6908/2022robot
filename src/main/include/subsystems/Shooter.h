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

#include <frc2/controller/PIDController.h>
#include <frc/controller/SimpleMotorFeedforward.h>

class Shooter: public frc2::SubsystemBase {
 public:
  Shooter();

  void setBottomMotorVoltage(units::voltage::volt_t);

  void setTopMotorVoltage(units::voltage::volt_t);

  double getTopVelocity(void);

  double getBottomVelocity(void);

  void stopShooter(void);

  static bool withinTolerance(double, double, double);


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

  double tkP = 0.0075;
  double tkI = 0;
  double tkD = 0;

  double tkS = 0.0643;
  double tkV = 0.128;
  double tkA = 0.0205;

  double bkP = 0;
  double bkI = 0;
  double bkD = 0;

  double bkS = 0.0496;
  double bkV = 0.129;
  double bkA = 0.0208;

  frc2::PIDContrller tpid{tkP, tkI, tkD};
  frc2::PIDController bpid{bkP, bkI, bkD};

  frc2::SimpleMotorFeedforward tff{tkS, tkV, tkA};
  frc2::SimpleMotorFeedforward bff{bkS, bkV, bkA};
};
