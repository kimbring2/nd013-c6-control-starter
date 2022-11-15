/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
   _Kp = Kpi;
   _Ki = Kii;
   _Kd = Kdi;
  
   _output_lim_max = output_lim_maxi;
   _output_lim_min = output_lim_mini;

   _prev_cte = 0;
   _int_cte = 0;
   _cte = 0;
   _diff_cte = 0;
}


void PID::UpdateError(double err) {
   /**
   * TODO: Update PID errors based on cte.
   **/
   _cte = err;
  
   _diff_cte = (_cte - _prev_cte) / _delta_time;
   _prev_cte = _cte;
   _int_cte += _cte * _delta_time;
}


double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
   double control;

   control = _Kp * _cte + _Kd * _diff_cte + _Ki * _int_cte;
  
   if (control <= _output_lim_min) {
     control = _output_lim_min;
   } else if (control >= _output_lim_max) {
     control = _output_lim_max;
   }

   return control;
}


double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
   _delta_time = new_delta_time;
}