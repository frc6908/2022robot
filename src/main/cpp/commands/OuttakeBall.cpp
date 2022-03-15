// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/OuttakeBall.h"

OuttakeBall::OuttakeBall(Intake* intake) : 
  m_intake{intake} {
  // Use addRequirements() here to declare subsystem dependencies.

  AddRequirements(intake);
}

// Called when the command is initially scheduled.
void OuttakeBall::Initialize() {
  this->m_intake->stopIntake();
}

// Called repeatedly when this Command is scheduled to run
void OuttakeBall::Execute() {
  this->m_intake->setIntakeMotor(-0.5);
}

// Called once the command ends or is interrupted.
void OuttakeBall::End(bool interrupted) {
  this->m_intake->stopIntake();
}

// Returns true when the command should end.
bool OuttakeBall::IsFinished() {
  return false;
}