
# Tree and Forest Growth Simulator

**Data Structures and Algorithms — Efrei Paris**

This project was developed in C as part of the TI301 Data Structures and Algorithms course at Efrei Paris.

The objective is to simulate the growth of trees over several seasons, first individually, then within a forest where trees compete for sunlight. The final part of the project focuses on analysing the results of multiple forest simulations using statistical methods.

The project covers dynamic memory allocation, pointers, recursive algorithms, queues, tree traversal, probabilistic simulations, and data analysis.

## Project Overview

The project is divided into three parts:

1. **Tree Growth:** Implementing individual tree growth using dynamic structures and probabilistic branching.
2. **Forest Simulation:** Simulating multiple trees growing together, with sunlight affecting their development.
3. **Statistical Analysis:** Running simulation campaigns, collecting measurements, and analysing their distributions.

Each part builds on the previous one.

## Part 1 — Tree Growth

The first part focuses on creating and growing an individual tree.

A tree is represented by a dynamic structure of connected branches. Each branch contains information about its position, direction, length, generation, and children.

At each season, active buds may generate new branches according to predefined probabilities.

### Main Features

- Creating and managing trees with dynamically allocated structures.
- Generating branches with randomized directions and lengths.
- Simulating tree growth over several seasons.
- Managing active buds using FIFO queues.
- Growing trees one season at a time.
- Traversing tree structures using Breadth-First Search (BFS).
- Saving trees to text files.
- Freeing dynamically allocated memory.

The queue-based implementation allows buds to be processed in their order of appearance without having to traverse the entire tree at every season.

### Branch Generation

In full sunlight, a bud may generate one, two, or three branches.

| Number of branches | Probability |
|--------------------|-------------|
| 1 | 70% |
| 2 | 25% |
| 3 | 5% |

The direction and length of each branch are determined using a seeded pseudo-random generator.

Using the same seed produces reproducible simulations.

## Part 2 — Forest Simulation

The second part extends the simulation to multiple trees growing in the same environment.

The main difference from Part 1 is that tree growth now depends on the amount of sunlight received by each bud.

Trees can affect one another's growth by blocking sunlight.

### Tree Measurements

Several measurements are maintained during tree growth:

- Total number of branches
- Tree height
- Maximum altitude
- Horizontal extension
- Number of active buds

Recursive functions are also used to independently verify these measurements.

### Light-Dependent Growth

The probability of growth depends on the available sunlight.

| Light intensity | Growth probability |
|-----------------|-------------------|
| L >= 0.7 | 95% |
| 0.4 <= L < 0.7 | 70% |
| 0.15 <= L < 0.4 | 40% |
| L < 0.15 | 0% |

The number of branches that can grow also changes depending on light intensity.

Branch length is calculated using:

`length = (0.5 + 0.5 * L) * u`

Where:

- `L` represents the amount of available sunlight.
- `u` is a random value between 0.7 and 1.3.

As sunlight decreases, branch growth becomes less likely and new branches tend to be shorter.

### Forest Representation

The forest is represented using dynamically allocated two-dimensional grids.

Two grids are used:

- **Occupancy grid:** Stores the number of branch tips located in each cell.
- **Light grid:** Stores the amount of sunlight available in each cell.

Sunlight is calculated from the top of the forest toward the ground. Each branch tip absorbs a proportion of the light passing through its cell.

The simulation also supports horizontal wrapping at the forest boundaries.

### Seasonal Simulation

Each simulated season follows the same sequence:

1. Calculate the available sunlight using the current forest occupancy.
2. Process the active buds of each tree.
3. Determine whether each bud can grow.
4. Generate new branches according to the available light.
5. Update tree measurements and forest occupancy.

The simulation can be configured with different numbers of trees, tree spacing, light absorption, random seeds, and numbers of seasons.

A maximum branch limit can also be applied to each tree.

### Validation

One of the final tests simulates a forest using the following parameters:

| Parameter | Value |
|-----------|-------|
| Number of trees | 24 |
| Tree spacing | 3 |
| Light absorption | 0.25 |
| Number of seasons | 32 |
| Random seed | 1 |

The simulation generates **6,809 branches**.

Some results from this simulation are:

| Measurement | Tree 0 | Tree 7 |
|-------------|--------|--------|
| Number of branches | 352 | 17 |
| Height | 32 | 8 |
| Maximum altitude | 33.009 | — |
| Horizontal extension | 17.479 | 3.941 |
| Active buds | 87 | — |

Tests conducted on ten forests reported no inconsistencies in tree measurements or occupancy grids.

Repeated simulations using the same parameters and random seeds also produced identical tree structures.

The saved forest file differs from the reference file on two branch-direction values, each by 0.01 degrees.

## Part 3 — Statistical Analysis

The third part focuses on studying the results of multiple forest simulations.

Instead of analysing a single forest, the program runs several simulations with identical parameters but different random seeds.

The measurements are exported to CSV files and then analysed using descriptive statistics and histograms.

### Simulation Campaigns

The program supports configurable simulation campaigns.

The available parameters include:

| Parameter | Description |
|-----------|-------------|
| `--K` | Number of trees per forest |
| `--E` | Spacing between trees |
| `--A` | Light absorption coefficient |
| `--S` | Number of seasons |
| `--R` | Number of forests |
| `--graine` | Initial random seed |
| `--identique` | Use identical initial trunk heights |
| `--sortie` | Output file prefix |

Each forest is simulated independently, using a different random seed.

Only one forest needs to be stored in memory at a time.

### CSV Export

Each campaign produces two CSV files:

- `*_arbres.csv`: Individual measurements for every tree.
- `*_forets.csv`: Total branch count and average measurements for each forest.

The exported data includes:

- Number of branches
- Tree height
- Maximum altitude
- Horizontal extension
- Truncation status
- Average maximum altitude per forest
- Average horizontal extension per forest

These files can be analysed using the program or opened with spreadsheet software.

### Statistical Functions

The analysis program provides:

- Arithmetic mean
- Standard deviation
- Minimum and maximum values
- Median
- First and third quartiles
- Skewness
- Histogram computation

Histograms can be displayed directly in the terminal or exported as SVG files.

The number of histogram classes can be specified when running the program.

### Simulation Results

Two campaigns were executed using the same parameters:

| Parameter | Value |
|-----------|-------|
| Trees per forest | 50 |
| Tree spacing | 3 |
| Light absorption | 0.25 |
| Number of seasons | 120 |
| Initial random seed | 101 |
| Initial trunk heights | Random |

The campaigns differ only in the number of forests simulated.

| Campaign | Forests | Total trees | Execution time |
|----------|---------|-------------|----------------|
| C1 | 40 | 2,000 | 4.893 s |
| C2 | 400 | 20,000 | 45.775 s |

The execution times were measured on the development computer and may vary depending on the system.

The 40 forests from campaign C1 correspond to the first 40 forests from campaign C2.

### Statistical Results

The following results were calculated from the generated CSV files.

| Measurement | Mean | Standard deviation | Skewness |
|-------------|------|-------------------|----------|
| C1 — Tree tops | 52.3644 | 39.8709 | 0.7765 |
| C1 — Tree extensions | 16.3505 | 9.4872 | 1.0683 |
| C2 — Tree tops | 53.3947 | 39.9240 | 0.7113 |
| C1 — Average tree tops per forest | 52.3644 | 2.9141 | 1.6758 |
| C2 — Average tree tops per forest | 53.3947 | 3.0653 | 0.2931 |
| C2 — Average extensions per forest | 16.4933 | 0.6047 | 0.2409 |

Some numerical values differ slightly from the reference results provided in the assignment. The statistical report uses the measurements obtained from our simulations.

### Observations

The analysis highlights several differences between individual tree measurements and forest averages.

Individual tree tops have a distribution with two main peaks: one corresponding to relatively small trees and another corresponding to trees that reached much greater heights.

Tree extensions have a different distribution, with one main peak and a longer tail toward higher values.

When measurements are averaged across the 50 trees of each forest, their distributions become much more concentrated.

With 400 forests, the distributions of average tree tops and extensions are approximately bell-shaped and considerably less dispersed than the individual measurements.

The complete analysis, including answers to the assignment questions, is available here:

**[Part 3 — Statistical Analysis](analyse_partie3.md)**

### Generated Histograms

The following SVG files illustrate the results of the statistical analysis.

| Histogram | Description |
|-----------|-------------|
| [C1_cime.svg](C1_cime.svg) | Tree tops from 2,000 trees |
| [C1_extension.svg](C1_extension.svg) | Tree extensions from 2,000 trees |
| [C2_cime.svg](C2_cime.svg) | Tree tops from 20,000 trees |
| [C1_cime_moy.svg](C1_cime_moy.svg) | Average tree tops from 40 forests |
| [C2_cime_moy.svg](C2_cime_moy.svg) | Average tree tops from 400 forests |
| [C2_extension_moy.svg](C2_extension_moy.svg) | Average extensions from 400 forests |

## Data Structures and Algorithms

Several concepts studied during the course are used throughout the project.

**Dynamic trees:** Branches are represented by dynamically allocated nodes connected through pointers.

**Queues:** FIFO queues are used to process active buds and implement breadth-first traversal.

**Recursion:** Recursive algorithms are used for tree measurements, traversal, and memory management.

**Breadth-First Search:** BFS is used to serialize tree structures in a consistent order.

**Dynamic 2D arrays:** Occupancy and light grids represent the forest environment.

**Pseudo-random generation:** Random seeds control branching decisions and allow simulations to be reproduced.

**Statistical algorithms:** Sorting, aggregation, and histogram computation are used to analyse simulation results.

## Project Structure

The project is organized into several directories.

```text
Tree/
|
|-- include/
|   |-- arbre.h
|   |-- queue.h
|   |-- croissance.h
|   |-- croissance_step.h
|   |-- arbre_foret.h
|   |-- croissance_lumiere.h
|   |-- foret.h
|   |-- campagne.h
|   |-- statistiques.h
|   |-- sauver_arbre.h
|   |-- sauver_foret.h
|
|-- src/
|   |-- arbre.c
|   |-- queue.c
|   |-- croissance.c
|   |-- croissance_step.c
|   |-- arbre_foret.c
|   |-- croissance_lumiere.c
|   |-- foret.c
|   |-- campagne.c
|   |-- statistiques.c
|   |-- sauver_arbre.c
|   |-- sauver_foret.c
|   |-- main_p2_etape*.c
|   |-- main_p3_etape*.c
|   |-- ...
|
|-- cmake/
|   |-- partie2.cmake
|   |-- partie3.cmake
|
|-- data/
|-- output/
|-- utils/
|
|-- analyse_partie3.md
|-- C1_cime.svg
|-- C1_extension.svg
|-- C1_cime_moy.svg
|-- C2_cime.svg
|-- C2_cime_moy.svg
|-- C2_extension_moy.svg
|
|-- CMakeLists.txt
|-- README.md
```

The `src/` directory contains the implementations and test programs.

The `include/` directory contains the corresponding header files.

The `data/` directory contains reference files and test data.

The `output/` directory is used to store generated simulation files and intermediate results. Its contents are excluded from Git, except for the placeholder file.

## Installation and Execution

### Requirements

- C compiler supporting C11
- CMake 3.10 or later
- CLion or another compatible C development environment

### Clone the Repository

```bash
git clone https://github.com/fabio-devine/TI301_projet_INT1_devine_okou.git
cd TI301_projet_INT1_devine_okou
```

### Build

```bash
cmake -S . -B build
cmake --build build
```

Individual targets can also be compiled:

```bash
cmake --build build --target p2_etape_6
cmake --build build --target p3_etape_1
cmake --build build --target p3_etape_2
cmake --build build --target p3_etape_3
```

In CLion, select the required CMake target from the run configuration menu.

The working directory should be set to the project root so that relative file paths work correctly.

### Run a Simulation Campaign

To run campaign C1, use `p3_etape_1` with:

```text
--K 50 --E 3 --A 0.25 --S 120 --R 40 --graine 101 --sortie output/C1
```

For campaign C2:

```text
--K 50 --E 3 --A 0.25 --S 120 --R 400 --graine 101 --sortie output/C2
```

The generated CSV files are saved in the `output/` directory.

### Run a Statistical Analysis

Use the target `p3_etape_3`.

For example, to analyse the tops of the 2,000 trees from campaign C1:

```text
output/C1_arbres.csv cime 24 output/C1_cime.svg
```

The program displays the descriptive statistics and an ASCII histogram, then generates the corresponding SVG file.

The analysis tool can also be used with other numerical columns from the exported CSV files.

## Testing

The project includes test programs for the different development stages.

The main tests cover:

- Probabilistic branch generation
- Tree growth and seasonal simulation
- Queue operations
- Tree measurements
- Breadth-first serialization
- Growth under different sunlight conditions
- Forest occupancy grids
- Sunlight computation
- Forest reproducibility
- CSV export
- Histogram computation
- Statistical calculations

The forest simulations passed the measurement, occupancy, and reproducibility tests performed during development.

The statistical campaign outputs are internally consistent, although some values differ slightly from the assignment's numerical references.

## Technologies

- **C11:** Main programming language
- **CMake:** Build configuration
- **CLion:** Development and debugging
- **Git and GitHub:** Version control and collaboration
- **CSV:** Exporting simulation data
- **SVG:** Generating statistical histograms

## Authors

**Victor OKOU**  
Efrei Paris  
[GitHub — VictorOKOU](https://github.com/VictorOKOU)

**Fabio Devine**  
Efrei Paris  
[GitHub — fabio-devine](https://github.com/fabio-devine)

Developed as part of the TI301 Data Structures and Algorithms course at Efrei Paris.

## References

Official project instructions:

- [Part 1 — Tree Growth](https://nicolas-flasque-efrei.github.io/TI-301/projet/FR/)
- [Part 2 — Forest Simulation](https://nicolas-flasque-efrei.github.io/TI-301/projet/partie2/EN/)
- [Part 3 — Statistical Analysis](https://nicolas-flasque-efrei.github.io/TI-301/projet/partie3/EN/)

The project uses the specifications and starter files provided as part of the course.
