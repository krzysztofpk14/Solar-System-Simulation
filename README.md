# Solar System Simulation Project

This README file aim to explain the code of the simulation of the Solar System

> Note: Keep in mind that in this explenation the term 'vector' may be used in a mathematical context, as well as the object type.

## Introduction

The Solar System consits of the star named 'Sun' and planets: Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, and Neptune. The physics behind the motion of planets and stars are described by graviataional forces:

$\mathbf{F}_g = G M_S m \frac{\mathbf{r}}{r^3}$ 

Where $\mathbf{F}_g$ is a gravitational force, $G$ is a gravitaional constant, $M_S$ is the mass of the Sun, $m$ is the mass of the planet, $\mathbf{r}$ is the position vector of a planet with respect to Sun and $r$ the length of that vector.

Moreover, the motion of each planet can be discribed by its position and velocity vectors whose values can be calulated based on these equations:

$\mathbf{r} (t + \Delta t) = \mathbf{r} (t) + \mathbf{v} (t)$

$\mathbf{v}(t + \Delta t) = \mathbf{v} (t) - G M_S \frac{\mathbf{r}(t +\Delta t)}{(r(t + \Delta t)^3)}  \Delta t$

Begining with $\mathbf{r}(t)$ and $\mathbf{v} (t)$ one can calulate the positon and velocity of a given planet in any time $t$. The smaller the time step $\Delta t$ the more accurate the result will be.



## Model Parameters

- $\Delta t = 10 $ days - Time increasement, note that this time is converted to seconds (SI units) in the simpulation code
- $t_{max} =  dt$ Maximal time of simulation
- $m_s = 1.9891 \cdot 10^{30}$ Mass of the Sun
- $G = 6.6743 \cdot 10^{-11}$ Gravitational constant
- $x_0 = 0$ Initial x-position
- $y_0 = 1432 \cdot 10^{10}$ Initial y-position
- $v_{x_0} = 9.7 \cdot 10^{3}$ Initial x-component of velocity
- $v_{y_0} = 0$ Initial y-component of velocity



## Files and Folders

### Files

- `main.h` - This file imports libraries and definition of physical constants and initial conditions
- `man.cpp` - The main program of the simulation
- `matplotlibcpp.h` - matplotlib library implemented in C++
- `Vec2D.h` - vector class definition
- `Vec2D.cpp` - vector class methods
- `Planet.h` - Class definition of planet object
- `Planet.cpp` - planet class methods
- `Solar_System.h` - solar_system class difinition
- `Solar_System.cpp` - solar_system methods
- `planets.txt` - Contains names, initial position and velocities of planets. The layout of the columns is as follows: name, initial x-position $x_0$, initial y-position $y_0$, initial x comonent of velocity $v_{x_0}$, initial y-component of velocity $v_{y_0}$

### Folders
 
- `data` - this folder cointains files named after each planet. Each file contains information about planet's position in a given time. The layout of the files is as folows: time $t$, x-cooridnate $x(t)$, y-coordinate $y(t)$



## Classes

### 1. Vec2D - vector class

#### Private variables

- `x` - x-coordinate of a vector, Type double
- `y` - y-coordinate of a vector, Type double

#### Methods

- `planet()` - Constructor taking no argumants
- `planet(vec2d a, vec2d b)` - Constructor taking x and y arguments respectively
- `~planet()` - Destructor
- `get_x()` - Returns x-coordinate
- `get_y()` - Returns y-coordinate
- `set_x(double a)` - Sets x-coordinate, takes a double as an argument
- `set_y(double b)` - sets y_coordinate, takes double as an argument
- `add(vec2d vec)` - Addition of a vector, takes a vector as a argument
- `sub(vec2d vec)` - Subtration of a vector. Vector in the argument is subtracted from the vector that the method is applied to
- `scale(double a)` - Multilpication by a scalar. Takes a double as an argument

#### Operators

- `+` - addition operator, the x-coordinate and y-coordinate are added seperately
- `'-'` - subtraction operator, the Vec2D vector on the right of the operator is subtracted from the vector on the left of the operator
- `\*` - multiplication by a scalar operator, the vector must stand on the left of the operator, while scalar on the right, scalar must be a double type

### 2. Planet

#### Private variables

- `pos` - Position vector of a planet, type vec2d
- `vel` - Velocity vector of a planet, type vec2d
- `name` - Name of the planet, type string

#### Methods

- `planet()` - Constructor taking no arguments
- `planet(vec2d a, vec2d b)` - constructor taking position vector (vec2d) and velocity vector (vec2d) as arguments respectively
- `~planet()` - Destructor
 - `get_pos()` - Returns position vector, returns vector type
- `get_vel()` - Returns velocity vector, returns vector type
- `get_name()` - Returns a name of a planet as a string
- `set_pos(vec2d a)` - Sets a position vector, takes vector vec2d as an argument
- `set_vel(vec 2d b)` - Sets a velocity vecor, takes vector vec2d as an argument
- `set_name(string n)` - Sets a name of a planet, takes a string as an argument
- `delta_t()` - Changes the position vector and velocity vector of a planet based on time increasement. The change is based on the equations included in the introduction as well as model parameters. Note the time `dt` must be converted to seconds

### 3. Solar_System

#### Private variables

- `planets` - this is a vector containing elements of class `planet`
- `current_time` is the double type variable encoding current time of the simulation, in days
- `time_step` - time difference $\Delta t$ of a simulation in days, double type

#### Methods

- `solar_system(double d_t)` - constructor taking time simpulaton time step as an argument, which is assigned to `time_step` private variable. Sets `current_time` to zeto
- `~solar_system()` - destructor
- `draw()` - this method uses matplotlib to draw each planet of a solar system in a given time stamp. The title of the plot is a simulation day. The method reads the time and position of a planet from a planet's file in `data` folder and plots a smaller point for each time stamp. The latest position of a planet is drawn as a bigger dot. This function uses the time in days
- `system_evolve()` method used to update the position of the planets based on the model and to update current time of a simulation. This method uses `to_file()` method to write updated data to each planet's file in `data` folder.
- `to_file` - writes the current time of the simultion, x-position and y-position to a file named after the name of a planet.
- `from_file()` - reads the `planets.txt` file to exctract the name of each planet, it's initial position and velocity vector (Vec2D). Then writes the data to a `planets` vector.

## Authors
- Krzysztof Kuba
