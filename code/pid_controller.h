/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PID {
public:
   double _Kp;
   double _Ki;
   double _Kd;
   double _output_lim_max;
   double _output_lim_min;

   double _prev_cte;
   double _cte;
   double _diff_cte;
   double _int_cte;

   double _delta_time;

   /**
   * TODO: Create the PID class
   **/
   /*
   PID(double Kp, double Ki, double Kd, double output_lim_max, double output_lim_min)
      : _Kp(Kp),
        _Ki(Ki),
        _Kd(Kd),
        _output_lim_max(output_lim_max),
        _output_lim_min(output_lim_min){};

   ~PID (){};     
   */
    /*
    * Errors
    */


    /*
    * Coefficients
    */

    /*
    * Output limits
    */
  
    /*
    * Delta time
    */

    /*
    * Constructor
    */
    PID();

    /*
    * Destructor.
    */
    virtual ~PID();

    /*
    * Initialize PID.
    */
    void Init(double Kp, double Ki, double Kd, double output_lim_max, double output_lim_min);

    /*
    * Update the PID error variables given cross track error.
    */
    void UpdateError(double err);

    /*
    * Calculate the total PID error.
    */
    double TotalError();
  
    /*
    * Update the delta time.
    */
    double UpdateDeltaTime(double new_delta_time);
};

#endif //PID_CONTROLLER_H


