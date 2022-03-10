// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Shooter.h"
#include <cmath> 

Shooter::Shooter() {
  // Implementation of subsystem constructor goes here.
}

void Shooter::setBottomMotorVoltage(units::voltage::volt_t bottomVoltage){
  bottomSpark.SetVoltage(bottomVoltage);
  
}

void Shooter::setTopMotorVoltage(units::voltage::volt_t topVoltage){
  topSpark.SetVoltage(topVoltage);
}

double Shooter::getTopVelocity() {
  return topSpark.GetEncoder().GetVelocity() / 60;
}

double Shooter::getBottomVelocity() {
  return bottomSpark.GetEncoder().GetVelocity() / 60; // check these definitions for syntax i don't have the autocomplete rn
}

void Shooter::stopShooter(){
  bottomSpark.StopMotor();
  topSpark.StopMotor();
}

void Shooter::Periodic() { }

static bool Shooter::withinTolerance(double a, double b, double t) {
  return std::abs(a - b) <= t;
}