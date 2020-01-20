#pragma once

struct Player {
	int x, y;
	int speed;
	int offsetX, offsetY;
	bool direction[2] = { false, false }; //At the start, both directions (up and down) should be set to false
	ALLEGRO_BITMAP* bitmap = NULL;

	Player(int x, int y, int offsetX, int offsetY, int speed)
	{
		this->x = x;
		this->y = y;
		this->offsetX = offsetX;
		this->offsetY = offsetY;
		this->speed = speed;
		bitmap = al_create_bitmap(20, 100);
		al_set_target_bitmap(this->bitmap);
		al_clear_to_color(al_map_rgb(255, 255, 255)); //Make the player bitmap white
	}

	void setDirection(int direction, bool state)
	{
		this->direction[direction] = state;
	}

	void checkCollision()
	{
		if ((this->y - this->offsetY) <= 10)
		{
			this->y = this->offsetY + 10;
		}
		if ((this->y + this->offsetY) >= DISPLAY_HEIGHT - 10)
		{
			this->y = DISPLAY_HEIGHT - this->offsetY - 10;
		}
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

	void update()
	{
		move();
		checkCollision();
	}

	void draw()
	{
		al_draw_bitmap(this->bitmap, this->x-this->offsetX, this->y-this->offsetY, 0);
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