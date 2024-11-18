% Define the plant transfer function
num = 1;                % Numerator of plant
den = [70 50 0];        % Denominator of plant
plant = tf(num, den);   % Transfer function of plant

% Define the PID controller with gains: P, I, and D
Kp = 0.1;  % Proportional gain
Ki = 0;   % Integral gain
Kd = 0;   % Derivative gain
s = tf('s'); % define laplace var
N = 10; % Derivative filter coefficient

% Create the PID controller
controller = Kp + Ki/s + Kd * N/(1+N/s);
controller1 = 0.2 + Ki/s + Kd * N/(1+N/s);
controller2 = 0.05 + Ki/s + Kd * N/(1+N/s);

% Create the Feedback Function

% Create the closed-loop system (feedback system)
closed_loop_system = feedback(controller * plant, 1);
closed_loop_system1 = feedback(controller1 * plant, 1);
closed_loop_system2 = feedback(controller2 * plant, 1);

% Simulate the step response of the system (Distance Time graph)
step(closed_loop_system)
title('Distance vs Time')
hold on
step(closed_loop_system1)
step(closed_loop_system2)
ylabel('Distance (m)')
hold off