// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveAuton.h"

DriveAuton::DriveAuton(Drivetrain* drivetrain)
    : m_drivetrain{drivetrain} {

    AddRequirements(drivetrain); 
}

void DriveAuton::Initialize() {
    this->m_drivetrain->stop();
}

void DriveAuton::Execute() {
    this->m_drivetrain->setDriveMotors(-0.4, -0.4);
}

void DriveAuton::End(bool interrupted) {
    this->m_drivetrain->stop();
}

bool DriveAuton::IsFinished() {
    return false;
}
