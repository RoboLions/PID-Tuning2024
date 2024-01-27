// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <ctre/phoenix6/TalonFX.hpp>

class Robot : public frc::TimedRobot {
 private:
  static constexpr char const *CANBUS_NAME{"rio"};

  ctre::phoenix6::hardware::TalonFX leftLeader{1, CANBUS_NAME};
  ctre::phoenix6::hardware::TalonFX leftFollower{2, CANBUS_NAME};
  ctre::phoenix6::hardware::TalonFX rightLeader{3, CANBUS_NAME};
  ctre::phoenix6::hardware::TalonFX rightFollower{4, CANBUS_NAME};

  ctre::phoenix6::controls::DutyCycleOut leftOut{0}; // Initialize output to 0%
  ctre::phoenix6::controls::DutyCycleOut rightOut{0}; // Initialize output to 0%

  frc::XboxController joystick{0};

  int printCount{};

 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  void SimulationInit() override;
  void SimulationPeriodic() override;
};
