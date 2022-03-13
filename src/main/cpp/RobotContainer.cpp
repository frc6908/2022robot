// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <iostream>

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here
  
  // Configure the button bindings
  ConfigureButtonBindings();

  // need lambda function to capture the value of the double function for continuous data getting 
  m_drivetrain.SetDefaultCommand(ArcadeDrive(&m_drivetrain, [this] { return -m_joystick.GetY(); }, [this] { return m_joystick.GetX(); }, [this] { return m_joystick.GetThrottle(); }
  ));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  
  frc2::JoystickButton intakeBall(&m_joystick, 2); //Side Button
  frc2::JoystickButton uptakeBall(&m_joystick, 5);
  //frc2::JoystickButton flipDriveTrain(&m_joystick, 7);
  frc2::JoystickButton shoot(&m_joystick, 1);
  

  intakeBall.WhileHeld(IntakeBall(&m_intake));
  uptakeBall.WhileHeld(UptakeBall(&m_uptake));
  //flipDriveTrain.WhenPressed(m_drivetrain.flipDT());
  shoot.WhileHeld(Shoot(&m_shooter, &m_uptake, units::velocity::meters_per_second_t{50.0}, units::velocity::meters_per_second_t{50.0}));
}

frc2::Command* RobotContainer::GetAutonomousCommand() { 
  // An example command will be run in autonomous
  //return &m_autonomousCommand;
  return &m_driveAutoCommand;
}

