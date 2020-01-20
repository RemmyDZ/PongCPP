#pragma once
const int DISPLAY_WIDTH = 1000;
const int DISPLAY_HEIGHT = 600;

const int FPS = 75; //Change this to your display refresh rate for smoothest experience

const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

const int PAD_HEIGHT = 100;
const int PAD_WIDTH = 20;
const int PAD_OFFSET_X = PAD_WIDTH / 2;
const int PAD_OFFSET_Y = PAD_HEIGHT / 2;

const int PLAYER_SPEED = 5;
const int PLAYER_START_X = 20;
const int PLAYER_START_Y = DISPLAY_HEIGHT / 2;

const int COMPUTER_SPEED = 5;
const int COMPUTER_START_X = DISPLAY_WIDTH - 20;
const int COMPUTER_START_Y = DISPLAY_HEIGHT / 2;

const int BALL_SIZE = 10; //The ball is a square with BALL_SIZE * BALL_SIZE
const int BALL_OFFSET = BALL_SIZE / 2;
const int BALL_MIN_SPEED = 5;
const int BALL_MAX_SPEED = 30;
const int BALL_START_X = DISPLAY_WIDTH / 2;
const int BALL_START_Y = DISPLAY_HEIGHT / 2;

const int BOUNDARY_SIZE = 10; //Thickness of the boundaries on the top and bottom

bool isGameFinished = false;
bool redraw = true;