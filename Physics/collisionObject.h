#ifndef COLLISION_OBJECT_H
#define COLLISION_OBJECT_H

#include "../Math/Vector3D.h"

/*
 * Collision Objects can be added to object which will interact with other 
 * collision objects. The object has a position, geometry and type.
 * Currently to only collision boundary available is a box. The type
 * dictates how the object reacts when colliding with other objects.
 * Currently only three types are available -- the ones needed for pong.
 */

enum CollisionType
{
	bouncyBall,
	Wall,
	Player
};

class CollisionObject
{
public:
	CollisionObject(const Vector3& position, const Vector3& width, const CollisionType& type):
		m_position(position),
       		m_width(width),
		m_type(type)	{}

	// We'll start with only bounding boxes
	bool AABBCollision(CollisionObject& colObj);

	// Get func
	CollisionType getType() { return m_type; }
	Vector3 getPosition() {return m_position;}
	Vector3 getWidth() {return m_width;}
	// Set func
	void setPosition(Vector3 value)
	{m_position = value;}
private:
	Vector3 m_position;
	Vector3 m_width;
	CollisionType m_type;
};



#endif
