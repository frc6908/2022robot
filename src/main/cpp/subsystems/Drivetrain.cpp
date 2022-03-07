// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

Drivetrain::Drivetrain() {
    rightMotors.SetInverted(1); // inverts the right drive motors

}

void Drivetrain::setDriveMotors(double left, double right) {
    tab.Add("LeftMotor", left);
    tab.Add("RightMotor", right);
    if (flipped) {
        leftMotors.Set(-right);
        rightMotors.Set(-left);
    } else {
        leftMotors.Set(left);
        rightMotors.Set(right - 0.015);
    }
    //NetworkTableEntry testTab = Shuffleboard.getTab("Test").add("Pi", 3.14);
}

void Drivetrain::arcadeDrive(double throttle, double turn) {
    setDriveMotors(throttle + turn, throttle - turn);
}

void Drivetrain::stop() {
    leftMotors.Set(0);
    rightMotors.Set(0);
}

void Drivetrain::flipDT() {
    flipped = !flipped;
}
// This method will be called once per scheduler run
void Drivetrain::Periodic() {}
