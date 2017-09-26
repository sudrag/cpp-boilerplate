/**
 *  @file    test.cpp
 *  @author  Sudarshan Raghunathan
 *  @copyright Sudarshan Raghunathan 2017
 *  @brief Test fixture
 */
#include <gtest/gtest.h>
#include <memory>
#include <iostream>
#include "PID.hpp"

/**
 * @brief      PID controller tests run within a class
 */
class PIDTest : public ::testing::Test {
 protected:
  PID obj;  // Creates a test object
};

/**
 * @brief      Tests if the code is functioning
 */
TEST_F(PIDTest, flag) {
  EXPECT_EQ(1, 1);
}

/**
 * @brief      This test is for checking the accuracy of the Compute
 * function . After a certain number of iterations (100) the output velocity needs to
 * be within a certain tolerance of the desired velocity
 */
TEST_F(PIDTest, Compute) {
  float err_tolerance = 0.01;
  float des_vel = 10.0;
  float curr_vel = 1.0;
  curr_vel = obj.final_vel(des_vel, curr_vel);
  EXPECT_NEAR(des_vel, curr_vel, err_tolerance);
}

/**
 * @brief    Doublet Test- Two successive bump tests.
 * This test checks if the output velocity in 300 time steps
 * can fall within the tolerance of the desired velocity ,which fluctuates
 * from 10 to -10 and back to 1
 */

TEST_F(PIDTest, doublet) {
  float err_tolerance = 0.01;
  float des_vel = 10.0;
  float curr_vel = 0.0;
  curr_vel = obj.final_vel(des_vel, curr_vel);
  des_vel = -10;
  curr_vel = obj.final_vel(des_vel, curr_vel);
  des_vel = 0.0;
  curr_vel = obj.final_vel(des_vel, curr_vel);
  EXPECT_NEAR(des_vel, curr_vel, err_tolerance);
}
