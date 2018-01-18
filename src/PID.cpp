#include "PID.h"
#include <chrono>
#include <cmath>        // std::abs

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  this->p_error = 0;
  this->i_error = 0;
  this->d_error = 0;

  this->last_time = chrono::steady_clock::now();
}

void PID::UpdateError(double cte) {
  auto now = chrono::steady_clock::now();

  auto dt = chrono::duration_cast<chrono::milliseconds>(now - last_time).count();

  this->d_error = (cte - this->p_error);
  this->p_error = cte;
  this->i_error += cte;

  this->last_time = now;
}

double PID::TotalError() {
  return -(this->Kp * this->p_error) - (this->Kd * this->d_error) - (this->Ki * this->i_error);
}

