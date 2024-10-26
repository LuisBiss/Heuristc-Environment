# Heuristic Environment

To complete my Data Structures course for my Computer Engineering degree, I had to create a simple heuristic environment to address an NP problem. The professor selected a basic Routing Problem, similar to the [Travelling Salesman Problem](https://www.youtube.com/watch?v=KH0Ynb_zdIg).

## What is a Heuristic?
A heuristic is essentially a solution for problems large enough that they would take impractically long to solve with current processing power. Instead of finding the perfect solution, a heuristic provides a solution that is "good enough" to work. In this case, the code addresses a VRP (Vehicle Routing Problem), the simplest form of NP problem, as it only considers travel distance, without accounting for factors like weight or load limits.

## The Environment
The code uses three main structures to create the environment.

### Vector of Points
This is a _struct_ representing locations, consisting of `x` and `y` positions and an `id`.

### Distance Matrix
This matrix calculates the distances between all locations using the Pythagorean Theorem.

### Population Vector
A randomly generated vector of valid solutions and their values, ordered by a quicksort algorithm.
