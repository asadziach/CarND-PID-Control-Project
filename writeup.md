## The effects of PID
The “P” stands for “Propositional” part that applies steering in proportion to error input. It is just a multiple of error input. The problem is that it tends to oscillate as shown in below video:


[![P controller](https://i.imgur.com/5GvkUV3.png)](https://youtu.be/vWKYwhhgp60 "P Controller")

The “D” stands for derivative. It is a multiple of the rate of change of the error input. It is just a multiple of (current_error - previous_error), divided by time between the two.If time internal is always constant then it can be incorporated into the D constant directly. If the current error is less than previous error then this reduces the effect of “P” term and smooths out the system. In my project when I introduced the D part, the oscillations shown above were cured.

The “I” stands for Integral. It is the accumulated error term. In its simplest form it is just a running sum of error term. This can fix any bias in system, like misaligned wheels. Since this project uses simulator so no bias is present hence I term is zero

## How final parameters were chosen?
Manually. First altered the "P" part keeping "D and "I" zero. Then increased D from zero in increments of 0.1 and system stabilized quickly. Didn't need to touch the I part.

## Caveat
The use of PID for steering control is purely academic. PID is best suited for for simple situations where we don't have to bother with the ‘laws of physics, like cruise control or industrial valves. PID would fail when a fast moving car approaches a sharp turn. Since PID; in its purest form; only looks at current error, it would issue extreme steering angle correction when it would notice high error term as the car enters the turn. The inertia of a high velocity vehicle would overwhelm its tyre friction and the car would skid out of control. Similarly at high speeds a constant sampling interval and the delay between sensing input and turning physical wheels can lead to unstable behavior.
