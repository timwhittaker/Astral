// Pong built with the physics engine
// Rendering hard coded here but will 
// be moved to the render engine later

#include <iostream>
#include <GL/glut.h>
#include "Examples/pong/ball.h"
#include "Examples/pong/player.h"

// window size
GLint windowL = 400;
GLint windowH = 400;

// Define Players
Player* playerOne = new Player();
Player* playerTwo = new Player();

// Define Ball
Ball* ball = new Ball(playerOne,playerTwo);

// Initialize OpenGL stuff
void init( void )
{
  glClearColor( 1.0, 1.0, 1.0, 0.0 ); 
  glColor3f( 0.0f, 0.0f, 0.0f );      
  glPointSize( 4.0 );                 
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();                   
  gluOrtho2D( 0.0, windowL, 0.0, windowH );
}

// Controls
void Control1(int key, int x, int y)
{
        switch(key)
        {
                case GLUT_KEY_LEFT:
                        {
                                playerOne->moveLeft(10);
                                glutPostRedisplay();
                                break;
                        }
                case GLUT_KEY_RIGHT:
                        {
                                playerOne->moveRight(10);
                                glutPostRedisplay();
                                break;
                        }
        }
}

void Control2(unsigned char key, int x, int y)
{
        switch(toupper(key))
        {
                case 'A':
                        {
                                playerTwo->moveLeft(10);
                                glutPostRedisplay();
                                break;
                        }
                case 'D':
                        {
                                playerTwo->moveRight(10);
                                glutPostRedisplay();
                                break;
                        }
        }
}

// Display setup
void displayScene()
{
        // Setup the players display
        glBegin(GL_LINES);
                // First Player
                glColor3f(0,1,1);
                // Get current coordinates from player 1 class
                glVertex2i(playerOne->getCoord1(),playerOne->getCoord2());
                glVertex2i(playerOne->getCoord3(),playerOne->getCoord4());
                // Second Player
                glColor3f(0,1,1);
                // Get current coordinates from player 2 class
                glVertex2i(playerTwo->getCoord1(),playerTwo->getCoord2());
                glVertex2i(playerTwo->getCoord3(),playerTwo->getCoord4());
        glEnd();

        // Setup Ball display
        glPointSize(50);
        glBegin(GL_POINTS);
                glColor3f(0,0,1);
                glVertex2i(ball->getPosition().x,ball->getPosition().y);
        //        ball->simBall(10);
        glEnd();

        glFlush();
}

void display(){
        glClear(GL_COLOR_BUFFER_BIT);
        glLineWidth(33);
        displayScene();
}

// Need to figure out how to do this properly
// Currently makes a flickering ball!
void idle()
{
	glPointSize(50);
        glBegin(GL_POINTS);
                glColor3f(0,0,1);
                glVertex2i(ball->getPosition().x,ball->getPosition().y);
                ball->simBall(0.05);
        glEnd();

	glFlush();
	glutPostRedisplay();
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000/60,timer,0);
	ball->simBall(1.0);
}

// Main loop

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutInitWindowSize(windowL, windowH);
	glutCreateWindow("Pong");
	
	init();
	
	playerOne->setCoord2(1);
	playerOne->setCoord4(1);
	playerTwo->setCoord2((double)windowH-1);
	playerTwo->setCoord4((double)windowH-1);
	ball->setPosition(Vector3(400.0/2,400.0/2,0.0));
	ball->setVelocity(Vector3(1.0,0.7,0.0));

		
	glutSpecialFunc(Control1);
	glutKeyboardFunc(Control2);
	//glutIdleFunc(idle);
	glutTimerFunc(0,timer,0);
	glutDisplayFunc(display);
	
	glutMainLoop();
}
