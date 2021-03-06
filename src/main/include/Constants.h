// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <cmath>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace drivetrain {
    const int kLeftDriveTalonPort = 14;
    const int kLeftDriveVenomPort = 15;

    const int kRightDriveTalonPort = 12;
    const int kRightDriveVenomPort = 0; 

    const int kWheelDiameter = 6;
    
    const double kDT = 0.02;
}

namespace intake {
    const int kIntakeTalonPort = 4;
    const int kBottomFeederVictorPort = 5;
}

namespace uptake {
    const int kUptakeVictorPort = 8;
    const int kTopFeederVictorPort = 11;
}

namespace shooter {
    const int kBottomSparkPort = 2;
    const int kTopSparkPort = 13;
}

namespace limelight {
    const double kTargetHeight = 104;
    const double kCameraHeight = 26;
    const double kCameraAngle = 45;
}

namespace oi {
    const int kDriveJoystickPort = 0; // drive joystick
    const int kDriveControllerPort = 1; // operator ps5 controller
}