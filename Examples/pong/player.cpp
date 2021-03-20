#include <GL/glut.h>
#include "player.h"
#include <iostream>

extern int windowL;

Player::Player()
{
        this->coord1 = 0;
        this->coord2 = 0;
        this->coord3 = 0;
        this->coord4 = 0;

        // Set coord1, coord3 so that bar is centered
        this->coord1 = windowL/2-30/2;
        this->coord3 = windowL/2+300/2;
}

Player::~Player(){}

void Player::setCoord1(double coord){
        this->coord1=coord;
}
void Player::setCoord2(double coord){
        this->coord2=coord;
}
void Player::setCoord3(double coord){
        this->coord3=coord;
}
void Player::setCoord4(double coord){
        this->coord4=coord;
}

double Player::getCoord1(){
        return Player::coord1;
}
double Player::getCoord2(){
        return Player::coord2;
}
double Player::getCoord3(){
        return Player::coord3;
}
double Player::getCoord4(){
        return Player::coord4;
}

void Player::moveLeft(GLint move)
{
        // new position
        int newPos = getCoord1()-move;
       // Make sure we're still in screen
       if (newPos >=0)
       {
               setCoord1(newPos);
               setCoord3(getCoord3()-move);
               std::cout << "x1,x2: " << getCoord1() << "," << getCoord3() << std::endl;
       }
       else
       {
               setCoord1(0);
       }
                                      }

void Player::moveRight(GLint move)
{
       // new position
       int newPos = getCoord3()+move;
       // Make sure we're still in screen
       if (newPos <= windowL)
       {
               setCoord3(newPos);
               setCoord1(getCoord1()+move);
               std::cout << "x1,x2: " << getCoord1() << "," << getCoord3() << std::endl;
       }
       else
       {
               setCoord3(windowL);
       }
}

      
