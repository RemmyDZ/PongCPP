#pragma once

struct Player {
	int x, y;
	int speed;
	bool direction[2] = { false, false }; //At the start, both directions (up and down) should be set to false
	ALLEGRO_BITMAP* bitmap = NULL;

	Player(int x, int y, int speed)
	{
		this->x = x;
		this->y = y;
		this->speed = speed;
		bitmap = al_create_bitmap(20, 100);
		al_set_target_bitmap(this->bitmap);
		al_clear_to_color(al_map_rgb(255, 255, 255)); //Make the player bitmap white
	}

	void setDirection(int direction, bool state)
	{
		this->direction[direction] = state;
	}

	void move()
	{
		if (this->direction[UP])
		{
			this->y -= this->speed;
		}
		else if (this->direction[DOWN]) //Else if because player cannot move up and down at the same time
		{
			this->y += this->speed;
		}
	}

	void draw()
	{
		al_draw_bitmap(this->bitmap, this->x, this->y, 0);
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

struct Ball {
	int x, y;
	int speed;
	bool direction[8] = { false, false, false, false, false, false, false, false }; //Ball has 8 directions in total

	Ball(int x, int y, int speed, int startDirection)
	{
		this->x = x;
		this->y = y;
		this->speed = speed;
		this->direction[startDirection] = true;
	}
};