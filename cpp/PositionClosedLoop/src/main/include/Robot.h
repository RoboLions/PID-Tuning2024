// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "ctre/phoenix6/TalonFX.hpp"
#include <frc/TimedRobot.h>
#include <frc/XboxController.h>

class Robot : public frc::TimedRobot {
  ctre::phoenix6::hardware::TalonFX m_fx{0};
  ctre::phoenix6::controls::PositionVoltage m_voltagePosition{0_tr, 0_tps, true, 0_V, 0, false};
  ctre::phoenix6::controls::PositionTorqueCurrentFOC m_torquePosition{0_tr, 0_tps, 0_A, 1, false};
  ctre::phoenix6::controls::StaticBrake m_brake{};

  frc::XboxController m_joystick{0};

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
