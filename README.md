## Build

sudo apt update && sudo apt install -y libgtk2.0-dev libgl1-mesa-dev
conan profile new default --detect
conan profile update settings.compiler.libcxx=libstdc++11 default
conan install ..
cmake -DCMAKE_TOOLCHAIN_FILE=conan_paths.cmake _DCMAKE_BUILD_TYPE=Debug ..
cmake --build .

# life-of-boids in C++

## Overview

life-of-boids is an application/software developped in C++ to simulate a flock of birds in animation mode in order to show their individual behaviour and interaction with each other and the environment surrounding them.

In general lines, the project corresponds to an artificial life experience which permits to analyse collective and individual behaviour, in addition to providing fun user interaction.


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
