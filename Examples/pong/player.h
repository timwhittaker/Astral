#ifndef PLAYER_H
#define PLAYER_H

/*
 * Class for player
 */

class Player
{
public:
	Player();
        virtual ~Player();
        void setCoord1(double coord);
        void setCoord2(double coord);
        void setCoord3(double coord);
        void setCoord4(double coord);
        void moveLeft(GLint move);
        void moveRight(GLint move);
        double getCoord1();
        double getCoord2();
        double getCoord3();
        double getCoord4();

private:
	double coord1, coord2, coord3, coord4;

};

#endif
