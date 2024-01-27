// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/Pigeon2.hpp>
#include <ctre/phoenix6/CANcoder.hpp>

class Robot : public frc::TimedRobot {
  const std::string CANBUS_NAME = "";
  ctre::phoenix6::hardware::CANcoder m_cc{0, CANBUS_NAME};
  ctre::phoenix6::hardware::TalonFX m_fx{0, CANBUS_NAME};
  ctre::phoenix6::hardware::Pigeon2 m_p2{0, CANBUS_NAME};
  int m_printCount = 0;

  ctre::phoenix6::controls::DutyCycleOut m_dutycycle{0};

  frc::XboxController m_joystick{0};

  ctre::phoenix6::StatusSignal<units::turn_t>& m_ccpos = m_cc.GetPosition();
  ctre::phoenix6::StatusSignal<units::turn_t>& m_fxpos = m_fx.GetPosition();
  ctre::phoenix6::StatusSignal<units::degree_t>& m_p2yaw = m_p2.GetYaw();

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
