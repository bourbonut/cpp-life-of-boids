# Documentation for all functions and classes in folder myMath

## Class vec2

### Attributes
```cpp
private:
    double _x; // x coordinate
    double _y; // y coordinate
```

### Initialization
```cpp
public:
    vec2(); // return vec2(0, 0)
    vec2(double, double);
```

### Methods

```cpp
public:
    double x(); // return the x value
    double y(); // return the y value
    vec2 operator+(vec2 other); // add vectors
    vec2 operator-(vec2 other); // substract vectors
    vec2 operator*(vec2 other); // multiply vectors term by term
    vec2 operator*(double other); // scale the vector
    vec2& operator=(vec2& other); // assign vector
    double dot(vec2 other); // return the scalar product
    double norm(); // return the norm of the vector
    vec2 normalize(); // return the current vector normalized
    double angle(); // return the angle between the current vector and `vec2(1, 0)`
    double anglebt(vec2 other); // return the angle between the current vector and an other vector
    void print(); // display the vector in shell
```

## Functions

### distance
```cpp
double distance(vec2 a, vec2 b) // return the distance between `a` and `b`
```

### barycenter
```cpp
vec2 barycenter(std::vector<vec2> vecs) // return a `vec2` which has the coordinates of the barycenter of all `vec2`
```
