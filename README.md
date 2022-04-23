# Life of Boids in C++

![demo](./doc/assets/demo.gif)

## Table of Contents

- [I. Overview](./doc/contents/overview.md)
    - Build
    - Running the program
    - Commands
- [II. Work Methodology](./doc/contents/work_methodology.md)
- [III. Code Logic and Architecture](./doc/contents/code_logic_architecture.md)
    - Agent and Flock
    - Graphical Manager
- [IV. Continuous Integration](./doc/contents/continuous_integration.md)
- [V. Profiling and performance computing](./doc/contents/profiling_performance_computing.md)
- [VI. Conclusion and openings](./doc/contents/conclusion_openings.md)


## Improvements

In order to increase the frame rate when we increase the number of birds, we use [OpenMP](https://en.wikipedia.org/wiki/OpenMP) and [TBB](https://en.wikipedia.org/wiki/Threading_Building_Blocks).
The program is able to have around 25 FPS with `2 ** 14 = 16384` birds on a machine with 8 cores.

[Next (Overview)](./doc/contents/overview.md)
