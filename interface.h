#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "map.h"
#define DISPLAY_WIDTH   512
#define DISPLAY_HEIGHT  512
#define FPS 60

typedef struct image
{
    ALLEGRO_BITMAP* red;
    ALLEGRO_BITMAP* orange;
    ALLEGRO_BITMAP* yellow;
    ALLEGRO_BITMAP* green;
    ALLEGRO_BITMAP* blue;
    ALLEGRO_BITMAP* purple;
    ALLEGRO_BITMAP* choclolate;

    ALLEGRO_BITMAP* redStrip1;
    ALLEGRO_BITMAP* redStrip2;
    ALLEGRO_BITMAP* redWrap;
    ALLEGRO_BITMAP* orangeStrip1;
    ALLEGRO_BITMAP* orangeStrip2;
    ALLEGRO_BITMAP* orangeWrap;
    ALLEGRO_BITMAP* yellowStrip1;
    ALLEGRO_BITMAP* yellowStrip2;
    ALLEGRO_BITMAP* yellowWrap;
    ALLEGRO_BITMAP* greenStrip1;
    ALLEGRO_BITMAP* greenStrip2;
    ALLEGRO_BITMAP* greenWrap;
    ALLEGRO_BITMAP* blueStrip1;
    ALLEGRO_BITMAP* blueStrip2;
    ALLEGRO_BITMAP* blueWrap;
    ALLEGRO_BITMAP* purpleStrip1;
    ALLEGRO_BITMAP* purpleStrip2;
    ALLEGRO_BITMAP* purpleWrap;

    ALLEGRO_BITMAP* none;
    ALLEGRO_BITMAP* bg;
    ALLEGRO_BITMAP* field;

    ALLEGRO_EVENT alEvent;
    ALLEGRO_EVENT_QUEUE* alEventQueue;
    ALLEGRO_DISPLAY* display;
    ALLEGRO_TIMER *timer;
} image;

void interfaceSet(image* interface);
void interfaceShow(image* interface, candy* Map,int COL, int ROW);
int interfaceSwap(image* interface, candy* Map, int swap1[2], int swap2[2],int COL, int ROW);
void interfacedestroy(image* interface);



