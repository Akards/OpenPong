#include <stdlib.h>
#include <time.h>
#include "gs.h"
#include <SFML/System.hpp>
GS::GS(){
	ballX = 320;
    ballY = 240;
    leftY = 0;
    rightY = 0;
    Lscore = 0;
    Rscore = 0;
    angle = rand() % 19
    ;
    while (angle == 0 || angle == 5 || angle == 10 || angle == 15){
    	angle = rand() % 19;
    }
    wPressed = false;
    sPressed = false;
    DOWNPressed = false;
    UPPressed = false;
}

void GS::reset(){
	ballX = 320;
    ballY = 240;
    leftY = 0;
    rightY = 0;
    Lscore = 0;
    Rscore = 0;
    angle = rand() % 19;
    while (angle == 0 || angle == 5 || angle == 10 || angle == 15){
    	angle = rand() % 19;
    }
    wPressed = false;
    sPressed = false;
    DOWNPressed = false;
    UPPressed = false;
}
void GS::ResetAfterScore(){
	ballX = 320;
	ballY = 240;
	sf::Clock clock;
	sf::Time time = clock.getElapsedTime();
	while(time < sf::seconds(1.5)){
		time = clock.getElapsedTime();
	}
	angle = rand() % 19;
	while (angle == 0 || angle == 5 || angle == 10 || angle == 15){
		angle = rand() % 19;
    }
}
void GS::leftScores(){
	Lscore++;
	ResetAfterScore();
}
void GS::rightScores(){
	Rscore++;
	ResetAfterScore();
}
int GS::getballX(){
	return ballX;
}
int GS::getballY(){
	return ballY;
}
int GS::getleftY(){
	return leftY;
}
int GS::getrightY(){
	return rightY;
}
int GS::getRightScore(){
	return Rscore;
}
int GS::getLeftScore(){
	return Lscore;
}
void GS::upLeft(){
	if (leftY <= 0) return;
	leftY -= 3;
}
void GS::downLeft(){
	if (leftY >= 415) return;
	leftY += 3;
}
void GS::upRight(){
	if (rightY <= 0) return;
	rightY -= 3;
}
void GS::downRight(){
	if (rightY >= 415) return;
	rightY += 3;
}

void GS::moveBall(){
	if (angle < 0 || angle > 19){
		exit(1);
	}
	switch(angle){
	case 0:
		//shouldn't happen
		ballY += 5;
		break;
	case 1:
		ballY += 4;
		ballX += 1;
		break;
	case 2:
		ballY += 3;
		ballX += 2;
		break;
	case 3:
		ballY += 2;
		ballX += 3;
		break;
	case 4:
		ballY += 1;
		ballX += 4;
		break;
	case 5:
		//should never actually happen
		ballX += 5;
		break;
	case 6:
		ballY -= 1;
		ballX += 4;
		break;
	case 7:
		ballY -= 2;
		ballX += 3;
		break;
	case 8:
		ballY -= 3;
		ballX += 2;
		break;
	case 9:
		ballY -= 4;
		ballX += 1;
		break;
	case 10:
		//shouldn't happen
		ballY -= 5;
		break;
	case 11:
		ballY -= 4;
		ballX -= 1;
		break;
	case 12:
		ballY -= 3;
		ballX -= 2;
		break;
	case 13:
		ballY -= 2;
		ballX -= 3;
		break;
	case 14:
		ballY -= 1;
		ballX -= 4;
		break;
	case 15:
		//shouldn't happen
		ballX -= 5;
		break;
	case 16:
		ballY += 1;
		ballX -= 4;
		break;
	case 17:
		ballY += 2;
		ballX -= 3;
		break;
	case 18:
		ballY += 3;
		ballX -= 2;
		break;
	case 19:
		ballY += 4;
		ballX -= 1;
		break;
	}
}

void GS::wallCollision(){
	switch(angle){
	case 0:
		angle = 10;
		break;
	case 1:
		angle = 19;
		break;
	case 2:
		angle = 18;
		break;
	case 3:
		angle = 17;
		break;
	case 4:
		angle = 16;
		break;
	case 5:
		angle = 15;
		break;
	case 6:
		angle = 14;
		break;
	case 7:
		angle = 13;
		break;
	case 8:
		angle = 12;
		break;
	case 9:
		angle = 11;
		break;
	case 10:
		angle = 0;
		break;
	case 11:
		angle = 9;
		break;
	case 12:
		angle = 8;
		break;
	case 13:
		angle = 7;
		break;
	case 14:
		angle = 6;
		break;
	case 15:
		angle = 5;
		break;
	case 16:
		angle = 4;
		break;
	case 17:
		angle = 3;
		break;
	case 18:
		angle = 2;
		break;
	case 19:
		angle = 1;
		break;
	}
}

void GS::floorCeilingcollision(){
	switch(angle){
	case 0:
		angle = 10;
		break;
	case 1:
		angle = 9;
		break;
	case 2:
		angle = 8;
		break;
	case 3:
		angle = 7;
		break;
	case 4:
		angle = 6;
		break;
	case 5:
		angle = 15;
		break;
	case 6:
		angle = 4;
		break;
	case 7:
		angle = 3;
		break;
	case 8:
		angle = 2;
		break;
	case 9:
		angle = 1;
		break;
	case 10:
		angle = 0;
		break;
	case 11:
		angle = 19;
		break;
	case 12:
		angle = 18;
		break;
	case 13:
		angle = 17;
		break;
	case 14:
		angle = 16;
		break;
	case 15:
		angle = 5;
		break;
	case 16:
		angle = 14;
		break;
	case 17:
		angle = 13;
		break;
	case 18:
		angle = 12;
		break;
	case 19:
		angle = 11;
		break;
	}
}
