## I.   Overview

`life-of-boids` is an application/software developped in C++ to simulate a flock of birds in animation mode in order to show their individual behaviour and interaction with each other and the environment surrounding them.

In general lines, the project corresponds to an artificial life experience which permits to analyse collective and individual behaviour, in addition to providing fun user interaction.

## Dependencies

The application uses the package `conan` to manage C++ packages.
Simply run :
```
pip install conan
```
There are some potential packages required for Linux, you should run :
```
sudo apt update
sudo apt install -y libgtk2.0-dev libgl1-mesa-dev
```

## Build

To build the application, download the repository `cpp-life-of-boids` and create the `build` folder by running the following lines :
```
git clone https://github.com/bourbonut/cpp-life-of-boids
cd cpp-life-of-boids
mkdir build && cd build
```
Now, you will configure a `conan` profile :
```
conan profile new default --detect
conan profile update settings.compiler.libcxx=libstdc++11 default
```
To finish, compile the application (make sure you are in `build` folder) :
```
conan install ..
cmake -DCMAKE_TOOLCHAIN_FILE=conan_paths.cmake _DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

## Run the program

After having successfully built the program, the executable file to launch is `life-of-boids` in `./build/src`. By default, the program will be generated with a flock of 600 parrots.

Here are the different usages, you can configure the program with more precision using these options :

```
./life-of-boids.exe
./life-of-boids.exe flock_size
./life-of-boids.exe flock_size agent_type
./life-of-boids.exe flock_size agent_color agent_size view_range view_angle r_align r_sep r_cohe max_speed
```
The first two ones draw a flock of parrot. The third usage uses predetermined agents. Finally, the last command let you created your agents the way your want.
Special usage : `./life-of-boids r` to generate a fully random flock (birds are randomly generated).

### Options

- **flock_size** : The number of agents in the initial flock
- **agent_type** : Predetermined agents type, this value can be
  - `Parrot` : The "classic" flock
  - `Dove` : Weak cohesion, big range and angle of view, weak aligment
  - `Duck` : Good alignment and range of view but weak cohesion
  - `Ant` : Weak cohesion, strong separation, negative alignment
  - `Fly` : Strong cohesion, big angle of view and small range of view
-  **agent_color**  : Predetermined colors, this alue can be
  - `Red`
  - `Green`
  -  `Blue`
  - `White`
  - `Purple`
  - `Yellow`
  - `Grey`
  - Default color will be white for agents

- **agent_size** : The body size of an agent (int > 0)
- **view_range** : How far can an agent see (in pixel, int)
- **view_angle** : The angle of view of an agent (int)
- **r_align** : Relaxation of the alignment law (float)
- **r_sep** : Relaxation of the separation law (float)
- **r_cohe** : Relaxation of the cohesion law (float)
- **max_speed** : The maximum speed of an agent (int)

## Commands

This is a list of available commandes when in runtime :
- **SPACE** : Pauses the movement of agents
- **P** : Switches to triangle/dot display
- **UP ARROW** : Adds a parrot in position (0,0)
- **DOWN ARROW** : Removes the _last_ added agent of the flock
- **RIGHT CLIC** : Destroys agents within a 100 pixel range
- **LEFT CLIC** : Adds a predator to the flock, press **CTRL** while clicking to add a predator with no law (easier to control with ZQSD).
- **Z, Q, S, D** : Moves the last added predator respectively : up, left, down, right.

[Next]("./work_methodology.md")

[Previous]("../../README.md")
