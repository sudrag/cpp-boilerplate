/**
 *  @file    main.cpp
 *  @author  Sudarshan Raghunathan
 *  @copyright Sudarshan Raghunathan 2017
 */
#include <lib.hpp>
#include <iostream>
#include"PID.hpp"
int main() {
  PID obj1;
  double curr_vel = 1.0;
  double des_vel = 10.0;
  double final_vel = obj1.final_vel(des_vel, curr_vel);
  std::cout << "The final velocity is:" << final_vel;
  std::cout << "\nThe desired velocity was:" << des_vel;
}
