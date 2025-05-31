# Rapid life  
### Version: Beta 1.0

---

**Rapid life** is an ecosystem simulator written in C++ using the SFML library. The program allows you to observe interactions between animals and plants on a procedurally generated map.

## Environment Setup:

### Requirements:
- Linux
- g++ 11.4+
- SFML 2.5+
- Make

### Running (on Linux):
1. Build the project with `make` in project folder.
2. Run the program with `./bin/main`.

### Building:
1. Make sure you have the SFML library installed (`libsfml-dev`).
2. Build the project with `make`.
3. Run the program with `make run` or directly with `./bin/main`.

## Features:
- Simulation of animal and plant life on a map with various biomes.
- Multiple species, each with its own behavior logic.
- Breeding, aging, death, and inheritance (bloodline).
- Procedurally generated map with biomes (meadow, forest, water, savanna).
- Graphical interface based on SFML.
- Ability to view statistics of selected objects.
- Debug mode.

## Controls:
- Arrow keys – move the map
- PageUp/PageDown – zoom in/out
- F – select next object
- T – select next object list
- V – toggle animal vision
- R – toggle plant range
- Space – pause/start
- Backspace – debug mode
