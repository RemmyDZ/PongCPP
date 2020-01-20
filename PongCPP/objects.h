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
		bitmap = al_create_bitmap(PAD_WIDTH, PAD_HEIGHT);
		al_set_target_bitmap(this->bitmap);
		al_clear_to_color(al_map_rgb(255, 255, 255)); //Make the player bitmap white
	}

	void setDirection(int direction, bool state)
	{
		this->direction[direction] = state;
	}

	void checkCollision()
	{
		if ((this->y - this->offsetY) <= BOUNDARY_SIZE)
		{
			this->y = this->offsetY + BOUNDARY_SIZE;
		}
		if ((this->y + this->offsetY) >= DISPLAY_HEIGHT - BOUNDARY_SIZE)
		{
			this->y = DISPLAY_HEIGHT - this->offsetY - BOUNDARY_SIZE;
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
	int offsetX, offsetY;
	int speed;
	bool direction[2] = { false, false };
	ALLEGRO_BITMAP* bitmap = NULL;

	Computer(int x, int y, int offsetX, int offsetY, int speed)
	{
		this->x = x;
		this->y = y;
		this->offsetX = offsetX;
		this->offsetY = offsetY;
		this->speed = speed;
		bitmap = al_create_bitmap(PAD_WIDTH, PAD_HEIGHT);
		al_set_target_bitmap(bitmap);
		al_clear_to_color(al_map_rgb(255, 255, 255));
	}

	void checkCollision()
	{
		if ((this->y - this->offsetY) <= BOUNDARY_SIZE)
		{
			this->y = this->offsetY + BOUNDARY_SIZE;
		}
		if ((this->y + this->offsetY) >= DISPLAY_HEIGHT - BOUNDARY_SIZE)
		{
			this->y = DISPLAY_HEIGHT - this->offsetY - BOUNDARY_SIZE;
		}
	}

	void move()
	{
		if (this->direction[UP])
		{
			this->y -= this->speed;
		}
		else if (this->direction[DOWN]) 
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
		al_draw_bitmap(this->bitmap, this->x - this->offsetX, this->y - this->offsetY, 0);
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