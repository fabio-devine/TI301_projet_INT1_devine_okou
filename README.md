# Tree and Forest Growth Simulator

**Data Structures and Algorithms — Efrei Paris**

This project was developed in C as part of the TI301 Data Structures and Algorithms course at Efrei Paris.

The goal is to simulate the growth of trees over several seasons, starting with a single tree and eventually extending the simulation to a forest where trees compete for sunlight.

The project focuses on the use of dynamic data structures, pointers, recursion, queues, and probabilistic algorithms.

## Project Description

The project is divided into two parts.

### Part 1 — Tree Growth

The first part focuses on the growth of an individual tree.

Each tree is represented by a dynamic structure of connected branches. At every season, its buds may produce new branches according to predefined probabilities.

The main functionalities include:

- Creating and managing a tree using dynamically allocated structures.
- Generating new branches with randomized directions and lengths.
- Simulating growth over multiple seasons.
- Managing active buds using FIFO queues.
- Simulating growth one season at a time.
- Traversing trees using Breadth-First Search (BFS).
- Saving generated trees to text files.

The queue-based implementation makes it possible to process buds in their order of appearance without traversing the entire tree at every season.

### Part 2 — Forest Simulation

The second part extends the simulation to multiple trees growing in the same environment.

Unlike the first part, tree growth now depends on the sunlight available at each bud's position.

The main functionalities include:

- Calculating tree measurements such as height, maximum altitude, horizontal extension, and number of buds.
- Adjusting growth probabilities according to light intensity.
- Reducing branch lengths when sunlight is limited.
- Representing the forest with dynamically allocated 2D grids.
- Tracking the position of branches in an occupancy grid.
- Computing sunlight levels based on the branches located above each cell.
- Simulating several trees growing simultaneously.
- Limiting tree growth when a maximum number of branches is reached.
- Saving complete forest simulations to text files.

The forest is simulated season by season. Sunlight is calculated first, and each tree then grows according to the light received by its buds.

This approach makes it possible to observe how trees influence one another's development.

## Growth Model

### Branch Generation

When a bud grows, it can generate one, two, or three new branches.

In full sunlight, the probabilities are:

| Number of branches | Probability |
|--------------------|-------------|
| 1 | 70% |
| 2 | 25% |
| 3 | 5% |

The direction and length of each new branch are also determined using random values.

### Light-Dependent Growth

In the forest simulation, the probability of growth depends on the light received by each bud.

| Light intensity | Growth probability |
|-----------------|-------------------|
| L >= 0.7 | 95% |
| 0.4 <= L < 0.7 | 70% |
| 0.15 <= L < 0.4 | 40% |
| L < 0.15 | 0% |

Branch length is adjusted using the following formula:

`length = (0.5 + 0.5 * L) * u`

Where `L` is the available light and `u` is a random value between 0.7 and 1.3.

### Sunlight Calculation

The forest is represented by two grids:

- An occupancy grid that stores the number of branch tips in each cell.
- A light grid that stores the amount of sunlight available in each cell.

Sunlight is calculated from the top of each column to the bottom.

Each branch tip blocks a proportion of the light passing through its cell. The light received by a cell depends on the number of branch tips located in the rows above it.

This allows the simulation to model the effect of shading between trees.

## Main Data Structures and Algorithms

The project uses several data structures and algorithms covered during the course.

**Dynamic trees:** Each branch is represented by a structure containing its position, direction, length, and pointers to its children.

**Queues:** FIFO queues are used to manage active buds and perform breadth-first traversals.

**Recursion:** Recursive functions calculate tree measurements and free dynamically allocated branches.

**Breadth-First Search:** BFS is used to save tree structures in the expected order.

**Dynamic 2D arrays:** The forest uses dynamically allocated grids to store occupancy and sunlight information.

**Randomized algorithms:** A seeded pseudo-random generator determines growth decisions and ensures that simulations can be reproduced.

## Project Structure

The main implementation files are located in the `src/` and `include/` directories.

### Part 1

| File | Purpose |
|------|---------|
| `arbre.c` | Tree and branch creation |
| `croissance.c` | Branch generation and tree growth |
| `croissance_step.c` | Season-by-season growth |
| `queue.c` | Queue implementation |
| `sauver_arbre.c` | Tree serialization using BFS |

### Part 2

| File | Purpose |
|------|---------|
| `arbre_foret.c` | Tree measurements and light-dependent branch growth |
| `croissance_lumiere.c` | Growth probabilities according to light intensity |
| `foret.c` | Forest creation, occupancy grids, light calculation, and simulation |
| `sauver_foret.c` | Forest serialization |

Additional files provide test programs, reference trees, random number generation, and visualization utilities.

## Installation and Execution

### Requirements

- A C compiler supporting C11
- CMake 3.10 or later
- CLion or another compatible IDE (optional)

### Clone the repository

```bash
git clone https://github.com/fabio-devine/TI301_projet_INT1_devine_okou.git
cd TI301_projet_INT1_devine_okou
```

### Build the project

```bash
cmake -S . -B build
cmake --build build
```

The project provides several executable targets corresponding to the different development stages.

For example, to build the final forest simulation test:

```bash
cmake --build build --target p2_etape_6
```

Run the executable from the project root directory so that relative paths such as `data/` and `output/` work correctly.

In CLion, select the desired CMake target and run it.

## Testing and Validation

The project includes test programs for the different stages of development.

The tests cover:

- Growth probabilities and random draws.
- Tree measurements and recursive calculations.
- Consistency between full and incremental growth.
- Tree growth under different light conditions.
- Occupancy grid calculations.
- Sunlight distribution.
- Forest reproducibility with fixed random seeds.
- Serialization of generated trees and forests.

### Forest Simulation Results

One of the final tests simulates a forest with the following parameters:

| Parameter | Value |
|-----------|-------|
| Number of trees | 24 |
| Tree spacing | 3 |
| Light absorption | 0.25 |
| Number of seasons | 32 |
| Random seed | 1 |

The simulation produces **6,809 branches**.

Some results from this simulation:

| Measurement | Tree 0 | Tree 7 |
|-------------|--------|--------|
| Number of branches | 352 | 17 |
| Height | 32 | 8 |
| Maximum altitude | 33.009 | — |
| Horizontal extension | 17.479 | 3.941 |
| Number of buds | 87 | — |

The validation tests reported no inconsistencies in tree measurements or occupancy grids across ten simulated forests.

Simulations using the same parameters and random seed also produced identical tree structures.

The generated forest file matches the reference data apart from two branch-direction values differing by 0.01 degrees due to floating-point rounding.

## Technologies

- **C (C11)** — Implementation
- **CMake** — Build configuration
- **CLion** — Development and debugging
- **Git and GitHub** — Version control and collaboration

## Authors

**Victor OKOU**  
Efrei Paris  
[GitHub](https://github.com/VictorOKOU)

**Fabio Devine**  
Efrei Paris  
[GitHub](https://github.com/fabio-devine)

This project was completed as part of the TI301 coursework at Efrei Paris, using the project specifications and starter files provided by the course.

## Academic Context

**Institution:** Efrei Paris  
**Course:** TI301 — Data Structures and Algorithms  
**Programming language:** C  
**Project:** Tree and Forest Growth Simulation

Project instructions: [Efrei TI301 — Part 1](https://nicolas-flasque-efrei.github.io/TI-301/projet/FR/) | [Part 2](https://nicolas-flasque-efrei.github.io/TI-301/projet/partie2/EN/)
