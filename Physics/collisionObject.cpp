#include <iostream>
#include "collisionObject.h"

/*
 * Collision Objects can be added to object which will interact with other
 * collision objects. The object has a position, geometry and type.
 * Currently to only collision boundary available is a box. The type
 * dictates how the object reacts when colliding with other objects.
 * Currently only three types are available -- the ones needed for pong.
 */


bool CollisionObject::AABBCollision(CollisionObject& colObj)
{
	std::cout<<"Testing AABB"<<std::endl;
	std::cout<<"Center distances: "<<fabs(m_position.x-colObj.getPosition().x)<<std::endl;
	std::cout<<"width sum: "<<m_width.x+colObj.getWidth().x<<std::endl;

	if(fabs(m_position.x-colObj.getPosition().x)>(m_width.x+colObj.getWidth().x)) return false;
	if(fabs(m_position.y-colObj.getPosition().y)>(m_width.y+colObj.getWidth().y)) return false;
	if(fabs(m_position.z-colObj.getPosition().z)>(m_width.x+colObj.getWidth().z)) return false;

	return true;
}
