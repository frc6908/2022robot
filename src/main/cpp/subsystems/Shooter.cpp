// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Shooter.h"

Shooter::Shooter() {
  // Implementation of subsystem constructor goes here.
}

void Shooter::setBottomMotorVoltage(units::voltage::volt_t bottomVoltage){
  bottomSpark.SetVoltage(bottomVoltage);
}

void Shooter::setTopMotorVoltage(units::voltage::volt_t topVoltage){
  topSpark.SetVoltage(topVoltage);
}

void Shooter::stopShooter(){
  bottomSpark.StopMotor();
  topSpark.StopMotor();
}

void Shooter::Periodic() { }
