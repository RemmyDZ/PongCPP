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

	al_init_primitives_addon();
	al_install_keyboard();

	ALLEGRO_EVENT_QUEUE* event_queue;
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!isGameFinished)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);
		if (event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (event.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				isGameFinished = true;
				break;
			}
			//Player movement here
		}
		else if (event.type == ALLEGRO_EVENT_KEY_UP)
		{
			//Stop player movement here
		}
		else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			isGameFinished = true;
		}
	}

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_shutdown_primitives_addon();
	al_uninstall_keyboard();

	return 0;
}