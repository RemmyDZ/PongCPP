#pragma once

struct Player {
	int x, y;
	int speed;
	bool direction[2] = { false, false }; //At the start, both directions (up and down) should be set to false

	Player(int x, int y, int speed)
	{
		this->x = x;
		this->y = y;
		this->speed = speed;
	}
};

struct Computer {
	int x, y;
	int speed;
	bool direction[2] = { false, false };

	Computer(int x, int y, int speed)
	{
		this->x = x;
		this->y = y;
		this->speed = speed;
	}
};