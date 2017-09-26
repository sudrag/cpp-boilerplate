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
  return 1;
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
  for (int i = 0; i < steps; i++)
    curr_vel = controller(des_vel, curr_vel);
  return curr_vel;
}
