# Astral
First attempt at a C++ physics engine. 

Examples can be built by running 'make ARGS="example you want to compile"' on Linux. It requires OpenGL and Glut to run. Which you can get by running:
sudo apt-get install freeglut3-dev

Current examples include "Pong." These are simple games to test basic kinematics and collision detection.
There is no rendering engine and so all graphics are hard coded for each games. The plan is to make a simple render engine soon.

The engine is built following "Game Physics" by David H. Eberly and "Game Physics Engine Development" by Ian Millington.
