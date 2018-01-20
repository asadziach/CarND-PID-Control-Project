# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## The effects of PID
The “P” stands for “Propositional” part that applies steering in proportion to error input. It is just a multiple of error input. The problem is that it tends to oscillate as shown in below video:


[![P controller](https://i.imgur.com/5GvkUV3.png)](https://youtu.be/vWKYwhhgp60 "P Controller")

The “D” stands for derivative. It is a multiple of the rate of change of the error input. It is just a multiple of (current_error - previous_error), divided by time between the two.If time internal is always constant then it can be incorporated into the D constant directly. If the current error is less than previous error then this reduces the effect of “P” term and smooths out the system. In my project when I introduced the D part, the oscillations shown above were cured.

The “I” stands for Integral. It is the accumulated error term. In its simplest form it is just a running sum of error term. This can fix any bias in system, like misaligned wheels. Since this project uses simulator so no bias is present hence I term is zero

## How final parameters were chosen?
Manually. First altered the "P" part keeping "D and "I" zero. Then increased D from zero in increments of 0.1 and system stabilized quickly. Didn't need to touch the I part.

## Caveat
The use of PID for steering control is purely academic. PID is best suited for for simple situations where we don't have to bother with the ‘laws of physics, like cruise control or industrial valves. PID would fail when a fast moving car approaches a sharp turn. Since PID; in its purest form; only looks at current error, it would issue extreme steering angle correction when it would notice high error term as the car enters the turn. The inertia of a high velocity vehicle would overwhelm its tyre friction and the car would skid out of control. Similarly at high speeds a constant sampling interval and the delay between sensing input and turning physical wheels can lead to unstable behavior.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)
