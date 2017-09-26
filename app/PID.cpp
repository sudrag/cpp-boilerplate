/**
 *  @file    PID.cpp
 *  @author  Sudarshan Raghunathan
 *  @copyright Sudarshan Raghunathan 2017
 *  @brief Performing PID calculations
 */

#include "PID.hpp"

/**
 * @brief   Creates an object
 */
PID::PID() {
}
/**
 * @brief   Destroys an object
 */
PID::~PID() {
}
/**
 * @brief      Computes the new velocity
 *
 * @param[in]  des_vel   The target velocity
 * @param[in]  curr_vel  The current velocity
 *
 * @return     returns the corrected velocity
 */
double PID::controller(double des_vel, double curr_vel) {
  float e = des_vel - curr_vel;
  float d_response = Kd*(e - error_prev)/dt;
  integral += Ki*e*dt;
  error_prev = e;
  return curr_vel + (Kp*e + d_response + integral);
}
/**
 * @brief      Computes the final velocity after settling time has lapsed
 *
 * @param[in]  des_vel   The target velocity
 * @param[in]  curr_vel  The current velocity
 *
 * @return     returns the final velocity
 */
double PID::final_vel(double des_vel, double curr_vel) {
  PID obj;
  auto j = 0;
  while (j < 200) {
    siz.push_back(1);
    j++;
  }
  for (int i : siz)
    curr_vel = controller(des_vel, curr_vel);
  return curr_vel;
}
