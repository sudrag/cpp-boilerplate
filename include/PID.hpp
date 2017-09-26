/**
 *  @file    PID.hpp
 *  @author  Sudarshan Raghunathan
 *  @copyright Sudarshan Raghunathan 2017
 *
 *
 *  @brief PID header file that contains a class to implement a
 *  PID controller where the error between the target
 *  and desired values is reduced.
 */

#pragma once
#include <iostream>
#include <vector>

/**
 * @brief      Pid controller's class
 */
class PID {
 private:
  double Kp = 0.1;
  double Kd = 0.0005;
  double Ki = 0.00001;
  double settling_time = 0.1;
  double error = 0.0;
  double error_prev = 0.0;
  double integral = 0;
  int steps = settling_time / dt;
  std::vector<int> siz;

 public:
  double dt = 0.001;
  /**+
   * @brief   Creates an object
   */
  PID();
  /**
   * @brief   Destroys an object
   */
  ~PID();
  /**
   * @brief      Computes the new velocity
   *
   * @param[in]  des_vel   The target velocity
   * @param[in]  curr_vel  The current velocity
   *
   * @return     returns the corrected velocity
   */
  double controller(double des_vel, double curr_vel);
  /**
   * @brief      Computes the final velocity after settling time has lapsed
   *
   * @param[in]  des_vel   The target velocity
   * @param[in]  curr_vel  The current velocity
   *
   * @return     returns the final velocity
   */
  double final_vel(double des_vel, double curr_vel);
};

