#include <GL/glut.h>
#include "Math/Vector3D.h"
#include "Physics/physicsObject.h"
#include "player.h"

/*
 * Class for ball. Has some basic physics plus detects
 */

class Ball
{
public:
	Ball(Player* playerOne, Player* playerTwo);
	
	Vector3 getPosition() {return position;};
	Vector3 getVelocity() {return velocity;};

	void setPosition(Vector3 pos);
	void setVelocity(Vector3 vel);
	void setAcceleration(Vector3 acc);

	void simBall(double delta);
private:

	Player* playerOne;
	Player* playerTwo;

	Vector3 position;
	Vector3 velocity;
	Vector3 acceleration;
	double mass;
	
	PhysicsObject ballPhys;

	// Hard code collision detection here
	// Will be move to a more general collision
	// detector system under Physics
	void checkWallHit();
	void checkPlayerOneHit();
	void checkPlayerTwoHit();
};
