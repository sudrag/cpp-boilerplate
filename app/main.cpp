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
  int numSteps = 1000;
  float curr_vel = 1.0;
  float des_vel = 5.0;
  for (int i = 0; i < numSteps; i++) {
    curr_vel = obj1.controller(des_vel, curr_vel);
  }
  std::cout << "The final velocity is:" << curr_vel;
  std::cout << "\nThe desired velocity was:" << des_vel;
}
