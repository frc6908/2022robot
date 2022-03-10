// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Shoot.h"

Shoot::Shoot(Shooter* shooter, double topVelocity, double bottomVelocity) : 
  m_shooter{Shooter}, topVelocity{topVelocity}, bottomVelocity{bottomVelocity} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(Shooter);
}

// Called when the command is initially scheduled.
void Shooter::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void Shooter::Execute() {
  double tv = this->m_shooter.getTopVelocity();
  double bv = this->m_shooter.getBottomVelocity();

  if (Shooter.withinTolerance(tv, topVelocity)) {
      // DO SOMETHING 
  }

  this->m_shooter->tpid.SetSetpoint(this->topVelocity);
  this->m_shooter->bpid.SetSetpoint(this->bottomVelocity);

  double ctop = this->tpid->Calculate(tv);
  double cbot = this->tpid->Calculate(bv);

  this->m_shooter->setTopMotorVoltage(ctop + this->m_shooter->tff->Calculate(topVelocity));
  this->m_shooter->setBottomMotorVoltage(cbot + this->m_shooter->bff->Calculate(bottomVelocity));
}

// Called once the command ends or is interrupted.
void Shooter::End(bool interrupted) {
  this->m_shooter->setTopMotorVoltage(0);
  this->m_shooter->setBottomMotorVoltage(0);
}

// Returns true when the command should end.
bool Shooter::IsFinished() {
  return false;
}
