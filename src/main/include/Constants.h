// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

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
    const int kLeftDriveTalonPort = 3;
    const int kLeftDriveVenomPort = 0;

    const int kRightDriveTalonPort = 1;
    const int kRightDriveVenomPort = 2; 
}

namespace intake {
    const int kActuateTalonPort = 5;
    const int kIntakeVictorPort = 6;
}

namespace oi {
    const int kDriveJoystickPort = 0; // drive joystick
    const int kDriveControllerPort = 1; // operator ps5 controller
}