# 42WOB_Cube3D
Another project from 42Wolfsburg

Cube3D is a 3D graphics rendering engine developed as part of the 42 school curriculum. The engine is written in C and uses the MiniLibX graphics library for displaying the output on the screen.

The engine simulates a 3D world composed of walls and sprites, with the player's viewpoint being the center of the screen. The world is defined in a 2D map using characters to represent walls, empty spaces, and other objects. The engine uses the raycasting algorithm to simulate the 3D rendering, which involves tracing rays from the player's viewpoint to the walls and objects in the world and then determining how they intersect.

The project consists of a game where the player can walk around a maze and shoot at enemies to score points. The game has various features, including wall collisions, sprite rendering, texture mapping, and lighting effects. The player can also move around using the keyboard keys and look around using the mouse.

The codebase is well-organized and structured, with different functions handling various aspects of the game, such as rendering, movement, and collision detection. The engine also has a Makefile that allows for easy compilation and execution.

Overall, Cube3D is a challenging and exciting project that provides an excellent opportunity to learn about 3D graphics rendering and game development in C.