#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "gs.h"
using namespace std;

int main()
{
	//Set initial Game values:

    sf::RenderWindow window(sf::VideoMode(640, 480), "Open Pong", (sf::Style::Resize + sf::Style::Close));
    //initialize our paddles
    sf::RectangleShape Rpaddle(sf::Vector2f(10.f, 65.f));
    sf::RectangleShape Lpaddle(sf::Vector2f(10.f, 65.f));
    Rpaddle.setFillColor(sf::Color::White);
    Lpaddle.setFillColor(sf::Color::White);
    //initialize the ball;
    sf::CircleShape ball(10.f);
    ball.setFillColor(sf::Color::White);
    ball.setOutlineThickness(2.f);
    ball.setOutlineColor(sf::Color::Red);
    //set background shapes
    sf::RectangleShape dividingLine(sf::Vector2f(10.f,480.f));
    sf::CircleShape backGroundCircle(70.f);
    dividingLine.setFillColor(sf::Color::White);
    backGroundCircle.setFillColor(sf::Color::Black);
    backGroundCircle.setOutlineThickness(4.f);
    backGroundCircle.setOutlineColor(sf::Color::White);
    dividingLine.setPosition(320.f, 0.f);
    backGroundCircle.setPosition(255.f, 180.f);
    //initialize our score display
    sf::Font font;
    if(!font.loadFromFile("Grid.ttf")){
    	exit(2);
    }
    sf::Text Lscore;
    sf::Text Rscore;
    Rscore.setFont(font);
    Lscore.setFont(font);
    Lscore.setPosition(125, 20);
    Rscore.setPosition(515, 20);
    Lscore.setString("0");
    Rscore.setString("0");
    Rscore.setFillColor(sf::Color::White);
    Lscore.setFillColor(sf::Color::White);
    //set starting values for everything
    srand(time(NULL));
    GS gs;
    sf::Clock clock;
    sf::Time time;
    while (window.isOpen())
    {
		clock.restart();
		time = clock.getElapsedTime();
		while(time < sf::seconds(0.006)){
			time = clock.getElapsedTime();
		}
        sf::Event event;
        while (window.pollEvent(event))
        {
        	if (event.type == sf::Event::KeyPressed){
				if (event.key.code == sf::Keyboard::Escape) window.close();
				if (event.key.code == sf::Keyboard::W) gs.wPressed = true;
				if (event.key.code == sf::Keyboard::S) gs.sPressed = true;
				if (event.key.code == sf::Keyboard::Up) gs.UPPressed = true;
				if (event.key.code == sf::Keyboard::Down) gs.DOWNPressed = true;
				if (event.key.code == sf::Keyboard::R) gs.reset();
			} else if (event.type == sf::Event::KeyReleased){
				if (event.key.code == sf::Keyboard::W) gs.wPressed = false;
				if (event.key.code == sf::Keyboard::S) gs.sPressed = false;
				if (event.key.code == sf::Keyboard::Up) gs.UPPressed = false;
				if (event.key.code == sf::Keyboard::Down) gs.DOWNPressed = false;
			}
        }
        if (gs.wPressed) gs.upLeft();
        else if (gs.sPressed) gs.downLeft();
        if (gs.UPPressed) gs.upRight();
        else if (gs.DOWNPressed) gs.downRight();
        if(gs.getballY() <= 0 || gs.getballY() >= 480) gs.floorCeilingcollision();
        if((gs.getballX() >= 10 && gs.getballX() <= 20 &&
            gs.getballY() >= gs.getleftY()-10 && gs.getballY() <= gs.getleftY() + 65) ||
            gs.getballX() >= 620 && gs.getballX() <= 630 &&
            gs.getballY() >= gs.getrightY()-10 && gs.getballY() <= gs.getrightY() + 65) gs.wallCollision();
        if (gs.getballX() > 630) gs.leftScores();
    	if (gs.getballX() < 0) gs.rightScores();
        Rpaddle.setPosition(620, gs.getrightY());
        Lpaddle.setPosition(10, gs.getleftY());
        ball.setPosition(gs.getballX(), gs.getballY());
        gs.moveBall();
        Lscore.setString(to_string(gs.getLeftScore()));
        Rscore.setString(to_string(gs.getRightScore()));
        window.clear(sf::Color::Black);
        //window.draw(backSprite);
        window.draw(Rpaddle);
        window.draw(Lpaddle);
        window.draw(backGroundCircle);
        window.draw(dividingLine);
        window.draw(Rscore);
        window.draw(Lscore);
        window.draw(ball);
        window.display();
    }

    return 0;
}
