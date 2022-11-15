### Installation

Run the following commands to install the starter code in the Udacity Workspace:

Clone the <a href="https://github.com/udacity/nd013-c6-control-starter/tree/master" target="_blank">repository</a>:

`git clone https://github.com/udacity/nd013-c6-control-starter.git`

## Run Carla Simulator

Open new window

* `su - student`
// Will say permission denied, ignore and continue
* `cd /opt/carla-simulator/`
* `SDL_VIDEODRIVER=offscreen ./CarlaUE4.sh -opengl`

## Compile and Run the Controller

Open new window

* `cd nd013-c6-control-starter/project`
* `./install-ubuntu.sh`
* `cd pid_controller/`
* `rm -rf rpclib`
* `git clone https://github.com/rpclib/rpclib.git`
* `cmake .`
* `make` (This last command compiles your c++ code, run it after every change in your code)

## Testing

To test your installation run the following commands.

* `cd nd013-c6-control-starter/project`
* `./run_main_pid.sh`
This will silently fail `ctrl + C` to stop
* `./run_main_pid.sh` (again)
Go to desktop mode to see CARLA

If error bind is already in use, or address already being used

* `ps -aux | grep carla`
* `kill id`

## Project Instructions

In the previous project you built a path planner for the autonomous vehicle. Now you will build the steer and throttle controller so that the car follows the trajectory.

You will design and run the a PID controller as described in the previous course.

In the directory [/pid_controller](https://github.com/udacity/nd013-c6-control-starter/tree/master/project/pid_controller)  you will find the files [pid_controller.cpp](https://github.com/udacity/nd013-c6-control-starter/blob/master/project/pid_controller/pid_controller.cpp)  and [pid_controller.h](https://github.com/udacity/nd013-c6-control-starter/blob/master/project/pid_controller/pid_controller.h). This is where you will code your pid controller.
The function pid is called in [main.cpp](https://github.com/udacity/nd013-c6-control-starter/blob/master/project/pid_controller/main.cpp).

# Step 1: Build the PID controller object
Take a screenshot and add it to your report. The car should not move in the simulation.
<img src="images/step_1.png" width="800">

# Step 2: PID controller for throttle:
The car should have the higher velocity than the velocity at next point of the planned path 

[Comment of code](https://github.com/kimbring2/nd013-c6-control-starter/blob/8b4f6fbf70fc8b0fe980d34b8ef685dae77e9229/project/pid_controller/main.cpp#L355)

# Step 3: PID controller for steer:
The car should steer it's direction based on the yaw angle of car and the angle of current position and next point of the planned path.

<img src="images/pid_steer_reason.png" width="400">

[Comment of code](https://github.com/kimbring2/nd013-c6-control-starter/blob/8b4f6fbf70fc8b0fe980d34b8ef685dae77e9229/project/pid_controller/main.cpp#L318)

# Step 4: Evaluate the PID efficiency
## 1. Add the plots to your report and explain them (describe what you see)
### Steering Plot
<img src="images/test(0.20%2C%200.001%2C%200.50%2C%201.2%2C%20-1.2)/Figure_1.png" width="400">

### Throttle Plot
<img src="images/test(0.20%2C%200.001%2C%200.50%2C%201.2%2C%20-1.2)/Figure_2.png" width="400">

At first, I set the PID parameter for throttle as (0.20, 0.001, 0.02, 1.0, -1.0 / Kpi, Kii, Kdi, output_lim_maxi, output_lim_mini) for easy analyzing. Next, I start to increase the Kpi parameter to steer because the car can not steer enough to avoide the obstacle. However, only increasing the Kpi parameter is not enough because the car start to rotate the same place due to the high steering angle. 

Therefore, I start to increase the Kdi parameter to reduce the changing ratio of steer angle. After few incresing, the car stops to rotate the same place. Nevertheless, I realize that the car is too sensiteive to the distance beween the middle line. 

Thus, I finally start to decrease the Kii parameter to mitigate that. After few decresing the Kii parameter, the car finally start to avoid the obstacle smoothly.

##  2. What is the effect of the PID according to the plots, how each part of the PID affects the control command?
I think the Kpi parameter makes the car steer more when error is high. Additionally, the Kdi parameter prevents to the car from steering too much. Finally, the Kii parameter can be used to force the car comply with the middle line.

##  3. How would you design a way to automatically tune the PID parameters?
As we learn in this course, we can use the Twiddle algorithm to make the tuning process automatically. For example, we can write the bash script consist of all Linux terminal command for running the experiment.

##  4. PID controller is a model free controller, i.e. it does not use a model of the car. Could you explain the pros and cons of this type of controller?
### Pros
The model free controller is easily implemented because the math funtion for that is already developed. After that, we just need to find the good parameters for our situation. 

### Cons
When the model of system is not really complex, it is relatively easy to find the suitable parameter. However, it means there are systems where we can find the suitlable parameters how many times we try.

##  5. (Optional) What would you do to improve the PID controller?
I personally use the more advanced contollrer such as the Deep Reinforcement Learning that has more space to be implemented.
