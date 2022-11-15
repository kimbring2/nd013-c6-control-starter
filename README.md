# Step 1: Build the PID controller object
Take a screenshot and add it to your report. The car should not move in the simulation.
<img src="images/step_1.png" width="800">

# Step 2: PID controller for throttle:
[Comment](https://github.com/kimbring2/nd013-c6-control-starter/blob/8b4f6fbf70fc8b0fe980d34b8ef685dae77e9229/project/pid_controller/main.cpp#L355)

# Step 3: PID controller for steer:
[Comment](https://github.com/kimbring2/nd013-c6-control-starter/blob/8b4f6fbf70fc8b0fe980d34b8ef685dae77e9229/project/pid_controller/main.cpp#L318)
<img src="images/pid_steer_reason.png" width="800">

# Step 4: Evaluate the PID efficiency
<img src="images/test(0.01%2C%200.01%2C%200.01%2C%201.2%2C%20-1.2)/Figure_1.png" width="800">

1. Add the plots to your report and explain them (describe what you see)
2. What is the effect of the PID according to the plots, how each part of the PID affects the control command?
3. How would you design a way to automatically tune the PID parameters?
4. PID controller is a model free controller, i.e. it does not use a model of the car. Could you explain the pros and cons of this type of controller?
5. (Optional) What would you do to improve the PID controller?
