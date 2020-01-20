#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include"globals.h"
#include"objects.h"

int main()
{
	if (!al_init()) //Initialize Allegro and throw an error message when failing to do so
	{
		al_show_native_message_box(0, "Error", "Error", "Failed to initialize Allegro", 0, 0);
		return 0;
	}
	ALLEGRO_DISPLAY* display;
	display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT); //Create a display
	if (!display) //Throw an error message when display hasn't been created succesfully
	{
		al_show_native_message_box(0, "Error", "Error", "Could not create display", 0, 0);
		return 0;
	}
	al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_SUGGEST); //Use V-sync if available

	al_init_primitives_addon();
	al_install_keyboard();

	//Create timer
	ALLEGRO_TIMER* timer = NULL;
	timer = al_create_timer(1.0 / FPS);

	//Create event queue and register all events
	ALLEGRO_EVENT_QUEUE* event_queue;
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	//Create objects
	Player player(20, DISPLAY_HEIGHT / 2, 10, 50, 5);

	//Start timer
	al_start_timer(timer);

	while (!isGameFinished)
	{
		al_set_target_bitmap(al_get_backbuffer(display));
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);
		if (event.type == ALLEGRO_EVENT_TIMER)
		{
			player.move();
			redraw = true;
		}
		if (event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (event.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				isGameFinished = true;
				break;
			case ALLEGRO_KEY_W:
				player.setDirection(UP, true);
				break;
			case ALLEGRO_KEY_S:
				player.setDirection(DOWN, true);
				break;
			}
		}
		else if (event.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (event.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:
				player.setDirection(UP, false);
				break;
			case ALLEGRO_KEY_S:
				player.setDirection(DOWN, false);
				break;
			}
		}
		else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			isGameFinished = true;
		}
		if (redraw && al_is_event_queue_empty(event_queue)) //Only redraw when the timer ticks and there are no events to be handled
		{
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			//Draw objects here
			//al_draw_filled_rectangle(player.x, player.y, player.x + 20, player.y + 100, al_map_rgb(255, 255, 255));
			player.draw();
			al_flip_display();
		}
	}

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_bitmap(player.bitmap);
	al_shutdown_primitives_addon();
	al_uninstall_keyboard();

	return 0;
}