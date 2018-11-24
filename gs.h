
#ifndef GS_H
#define GS_H
class GS{
private:
	int ballX;
	int ballY;
	int leftY;
	int rightY;
	int Rscore;
	int Lscore;
	int angle;
public:
	GS();
	int getballY();
	int getballX();
	int getleftY();
	int getrightY();
	void upLeft();
	void downLeft();
	void upRight();
	void downRight();
	void moveBall();
	void wallCollision();
	void floorCeilingcollision();
	void reset();
	void leftScores();
	void rightScores();
	int getRightScore();
	int getLeftScore();
	void ResetAfterScore();
	bool wPressed;
	bool sPressed;
	bool UPPressed;
	bool DOWNPressed;

};
#endif
