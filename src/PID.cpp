#include "PID.h"
#include <chrono>

using namespace std;

/*
 * TODO: Complete the PID class.
 */

PID::PID() {
}

PID::~PID() {
}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  p_error = 0;
  i_error = 0;
  d_error = 0;

  last_time = chrono::steady_clock::now();
}

void PID::UpdateError(double cte) {
  auto now = chrono::steady_clock::now();

  std::chrono::duration<double> diff = now - last_time;
  double dt = diff.count();

  d_error = (cte - p_error) / dt;
  p_error = cte;
  i_error += cte * dt;

  last_time = now;
}

double PID::TotalError() {
  return -(Kp * p_error) - (Kd * d_error)
      - (Ki * i_error);
}

