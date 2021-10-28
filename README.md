# life-of-boids in C++

## Table of Contents

- [Overview](#Overview)
- [Build](#Build)
- [Running the program](#Running the program)
- [Commands](#Commands)
- [Code Architecture](#Code Architecture)
- [Graphical Manager](#Graphical Manager)

## Overview

life-of-boids is an application/software developped in C++ to simulate a flock of birds in animation mode in order to show their individual behaviour and interaction with each other and the environment surrounding them.

In general lines, the project corresponds to an artificial life experience which permits to analyse collective and individual behaviour, in addition to providing fun user interaction.

## Build

sudo apt update && sudo apt install -y libgtk2.0-dev libgl1-mesa-dev
conan profile new default --detect
conan profile update settings.compiler.libcxx=libstdc++11 default
conan install ..
cmake -DCMAKE_TOOLCHAIN_FILE=conan_paths.cmake _DCMAKE_BUILD_TYPE=Debug ..
cmake --build .

## Running the program

When built, the executable file to launch is **life-of-boids.exe**. By default, the program will be generated with a flock of 400 parrots.

Here are the different usages, you can configure the program with more precision using these options :
```
./life-of-boids.exe
./life-of-boids.exe flock_size
./life-of-boids.exe flock_size agent_type
./life-of-boids.exe flock_size agent_color agent_size view_range view_angle r_align r_sep r_cohe max_speed
```
The first two ones draw a flock of parrot. The third usage uses predetermined agents. Finally, the last command let you created your agents the way your want.
Special usage : ```./life-of-boids r``` to generate a _fully_ random flock, with _fully_ random birds in it.

### Options
  - **flock_size** : The number of agents in the initial flock
  - **agent_type** : Predetermined agents type, this value can be
   	   - ```Parrot``` : Angle view : range : ... + Cohesion high, separation low, etc...
   	   - ```Dove```
   	   - ```Duck```
   	   - ```Ant```
   	   - ```Fly```
  -  **agent_color**  : Predetermined colors, this alue can be
   	   - ```Red```
   	   - ```Green```
   	   -  ```Blue```
   	   - ```White```
   	   - ```Purple```
   	   - ```Yellow```
   	   - ```Grey```
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

## Code Architecture

![ULM diagram](assets/readme/ulmDiagram.png)

### The flock

The flock constitutes the ensemble of the environment, agents and interactions simulated by the program, in a way that only one flock can be generated and displayed to the user.

In technical terms, the flock is represented by a class, the highest class in the code hierarchy whose instantiated object will incorporate most of the other objects in the project. It hosts, for example, all of the birds and predators in the project.

The only attribute of this class is a vector of pointers to *Agents*. An Agent can be interpreted as a living being belonging to the flock, such as a bird or an eagle, which will interact with other agents around him. Thus, this vector points to the data representing the actual flock.

This vector can be modified according to agents or user interaction by the methods of the class Flock. Therefore, the vector (representing the flock) can grow, when an agent is added, or can decrease in size, when an agent is removed. It methods also permits to access information of the flock, such as its size or specific agent.

### Agent

As already stated, an agent is an active member, a living being of the flock. It is represented in the code by a class that, when instantiated, will create the objects belonging to the Flock vector.

In practice, though, this class can never be instantiated, as it intends only to be a parent class for two other child classes:

- Bird
- Eagle

Which instantiated objects will then inherite or override the general properties and methods of an agent.

The agent, for example, has a position and velocity representing the values perceived by the user in the last time step. In order to compute the interactions between agents/user in the current time step, another position and velocity are also stored, according to its own speed limit. Other properties related to the interface are body size and color.

The interaction between agents occurs only if they are within a certain range and view angle (according to its own movement direction). All this properties can be different pursuant to the agent type - eagle or bird (and even type of bird). In addition, each child class has its own specific attributes and methods to determine its behaviour.

The attributes in the Agent class, are all *protected*, thus they can only be accessed from its own methods or from their child classes, but not from outside. In the last case, interface methods are provided to access and set such properties.

### Bird

The objects of this class will represent, intuitively, the birds of a flock. The instantiation of a Bird is done by a constructor which will simply call the *Agent constructor* with certain specific values. The position and velocity, for example, are randomly chosen within certain boundaries, whereas the size, range and view angle (270°) are set to constant values.

The bird's behaviour, on the other hand, is determined by a group of rules/laws represented and computed by private methods:

* Cohesion law
* Separation law
* Fleeing law
* Alignment law

Each of these will contribute to modify the computed speed of the bird, and therefore its position and direction of movement.

#### Cohesion law

The cohesion law is the law responsible for the agents trying to move closer to their viable neighbors, as such a Bird will try to get closer to the Birds found in its field of vision.

In practice, this law computes a barycenter for all the viable neighbors who are in the visible range of a Bird and not in its vital avoidance cell. The displacement, which is the difference between the actual velocity of an agent and its next velocity, of this Bird will then be modified to enable reaching the location of this barycenter, more or less quickly depending on the relaxation of this law.

#### Separation law

The separation law is the law responsible for the agents not clustering on top of each others.

This effect is obtained using the inverse of the square distance between two agents as a weight, meaning that in practice closer two birds become the more the separation will be strong, up to a degree where it can virtually negate the effects of the other laws.

In practice, this law adds a component to the displacement of an agent representing the weighted sum of the movements created in the opposite direction of each chosen neighbors.

This law is used two times during a Bird displacement calculation, one with it's Birds neighbors, and one with it's Eagles neighbors using a higher weight to represent an attempt to "escape" (previously mentionned as fleeing law).

#### Alignment law

The alignement law is the law responsible for the tendency of the agents of a cluster, created by the effects of the two preceding laws, to obtain a common facing direction with their neighbors found in their respective fields of vision.

In practice, this law adds a component to the displacement of an agent representing a mean between the actual velocity of its viable neighbors.

### Eagle

The objects of this class will, intuitively, represent eagles. Eagles are predators, and their role in the flock is to chase birds and eat them.

Similar to the class Bird, this one also calls the *Agent constructor*, although with different parameters like a smaller size and range, different color and narrower view angle.

The behaviour of an eagle is also different from a bird, and it is determined by only one law:

*  Hunting law

As in *Birds*, these laws will be computed and modify the position and velocity of the eagle.

#### Hunting law

This law is responsible for the predator chasing the birds. If there are bids in the eagle's view angle and range, a random prey is chosen to be the focus of the chase at each time step. This means that the predator's velocity will scale according to the prey's velocity - that is, the eagle will intersect the bird at its next position.

If the eagle gets close enough to its prey, it will *feed* from it; In programming terms, the object *Bird* will be destroyed from memory and the removed from the Flock vector, also disappearing from the graphical user interface. After feeding, the eagle grows in size, until a certain limit; overcoming this limit, the predator will divide itself - that is, return to its original size and create 2 other predators in the same position.

![Hunting GIF](assets/readme/predatorAnimation.gif)

### Laws

The previously cited laws are children classes of a virtual parent class Law.

Those laws are the core of the design of this program, and represent most of its need for computing ressources when associated with the calculation of the neighbors needed to get the effects of a law on an agent.

In technical terms, the Law class includes in particular a protected relaxation variable which represents how smooth an agent will react to a given law, a protected law constructor which is used for the instantiation of its children classes, and a public method named compute which is overriden by each children laws in order to modify the next velocity value of an agent.

Having considered that, it is important to notice the interactions between the laws and not a law by itself, and in particular the complementary laws affecting a Bird.

The weighted outputs of these laws form, after theirs respectives relaxation are applied, the displacement, which is a change in velocity enabling Birds to form clusters and Eagles to track their prey.

### Compute neighbors, first version

In order to be able to calculate the laws of alignment, cohesion and separation, it was necessary to create the method "compute neighbors".

This method consists in going through a list of agents and checking the existence of a neighbor according to a precise range and to the angle of view of the agent (according to type of bird).

The first version of this method checked these conditions for all the viable agents (viable means here that only Birds will be considered for the cohesion law of a Bird).

### Flock generator and color

There are differents level of personalization of Flocks generating according to the choice of the user :

This code contributes to generate different types of Birds in a Flock (Duck, Ant, Dove, Parrot,...),

with differents attributes (flock_size, range, angle_view, agent_size, cohesion_relax, sep_relax, align_relax, speed_relax, position, velocity, agent_color).

The color of the birds can be chosen to be random.

![Colors](assets/readme/colors.png)

## Graphical Manager
The goal of the GraphicalManager class is to wrap-up all the OpenGL components of the code to make development easier.

The GraphicalManager constructor initializes and manages OpenGL variables and our graphical variables to help us draw the shapes we want.

Some of the tasks it is assigned are :
- Creates the window
- Sets up the shaders programs
- Activates the shaders programs
- Creates the OpenGL buffers
- Initializes and defines variables needed to draw our shapes
- Links our key and mouse callback functions with OpenGL event management
- Sets up the colors

This class also implements a method called "mainLoop" that, when called, executes one loop. Namely, it launches the calculations of the next positions of the Agents making them move and then proceeds to draw them. </br>
It's possible to draw the agents either as triangles or as points, even though at small number of agents it does not affect performance. We created a class "AgentDisplayer", called by GraphicalManager, implementing DotDisplayer and TriangleDisplayer to take care of the correct display conditionally. 

![Description of GM](assets/readme/DisplayerClasses.drawio.png "GraphicalManager")

It supports the display in windowed screen or fullscreen, and the Agent drawing as triangles or points.

Finally, the GraphicalManager destructor takes care of closing the window and cleaning the OpenGL variables before ending the program.


## Docker
In order to run the builds in Continuous Integration Pipelines, docker images are needed in order to execute the commands of the pipeline. Namely the different stages needed are : 
- The installation of the dependencies with conan
- The building job with various compilers
- Executing the tests

The first continuous integration pipelines were really time-consuming because it included downloading all the packages with conan commands. With the introduction of the <em> Clang </em> compiler, some of the dependencies weren't directly downloadable via conan. These packages needed to be downloaded as source code, and then built from source. This stage of building from source the missing packages is extremely long ( $\simeq$ 20 minutes) and it wasn't possible to wait this long at each pipeline. 

We decided to build new docker images, with prebuilt and installed dependencies for both compilers <em> GCC </em> and <em>Clang</em>. Two images were build from <em>conanio/gcc9</em> and <em>conanio/clang10</em> with our files.<br>
It enabled us to iterate faster on our portability with other compilers.

# User configuration
Now that we have implemented a flock generator, which can be used in many ways in the code, we want to be able to let the user configure his flock. This can be done by using options (c.f. chapter **Running the program - Options**).
To implement this, we used ```argv``` and ```argc[]``` parameter of the ```main``` function.
The order of the options are specific, and a different code is triggered depending on the number of arguments the user gave.

![Switch/case using argc parameter](assets/readme/switch_case_parameter)
These options are thought to be user-friendly, which means that the user will be informed if he/she entered a wrong number of arguments, of a weird number (e.g. a size of flock of 0). The program will either warn the user if he/she is fully configurating the flock (with all options possible), or it will throw an exception if the user wants to use the _easy_ options (0, 1, or 2 arguments).

![User warning for configuration](assets/readme/user_warning_parameter)
To be the most user friendly possible, we created some birds template, with given values for eveything (range and angle of view, size, color, laws' relaxations) so the user can try the program without knowing about the _complex_ options like laws' relaxations.

These options could have been managed in a easier way using the C++ library ```options```, allowing the user to mark the option he/she wanted with a dash ```-```. This will be integrated next release.

# Git management
It is not trivial to work in a team of seven people. At first, there we had no particular git management, the rule was to make a merge request on master when we felt our changes was good (compiles and runs on MSVC). Due to some accidental pushes on master, making the master branch not compilable, we started to think of a way to manage our git branches.
The idea was to make a new branch ```dev```, in which no one is allowed to push, one can only update it using merge requests. This ```dev``` branch is our main development branch, while the ```master``` branch is blocked both for pushing **and** merging.

The ```master``` branch is unlocked when we have a stable version of the program, that we know can be delivered. In such a case, we allow ```master``` to be merged, and when it is, we re-block it again. This both separates our final product, and our development product on two different branches, but it also covers us against accidental pushes on a branch that compiles and runs.

**IMAGE BRANCH BLOCKED ON GIT LAB**

Although this git management was way better than what we did at the beggining of the project, we were only building and testing our program on one compiler, MSVC. And all this had to be done by hand. The next thing we needed was to integrate continuous integration to our project.


# CI Pipeline
Now that we have a nice branch management, and a good merge request system, the only thing missing is a good pipeline which gets triggered for every push and merge request.
 We started by using the Docker image ```conanio/gcc9``` so conan and gcc are both included and we don't have to start an image from scratch.
 Some external packages are needed to compile and run our program : ```libgtk2.0-dev``` and ```libgl1-mesa-dev```. The installation of these files take a few minutes (about 5). Since the docker image is cleared at the beginning of a new pipeline, we had to make these installation everytime. Since a new pipeline is created for **every pull**, which means that the developper has to wait **5 minutes** everytime he/she pushes. Better not miss a semi-colon ! We will develop what actions we decided to take in order to palliate this issue. 
Now, when a developer pushes his/her branch, the new pipeline is triggered, the code is compiled on both GCC9 and Clang10 compilers, and tests are run on both these environments. In a merge request process, if the pipeline has not succeeded, the request is blocked until someone pushes a commit to fix the issue. This workflow allows us to continuously keep a clean code, which is portable on 3 different compilers. 
All of this experience has shown us that some compilers do work that other won”t do, in which case we have to make this work explicit it in the code (most often is include problems, MSVC will automatically include some files and library needed for the project, which Clang won’t do).

