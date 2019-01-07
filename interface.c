#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "interface.h"

void interfaceSet(image* interface)
{
    interface->alEventQueue= al_create_event_queue();
    interface->display= al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    interface->red    = al_load_bitmap("./red.png");
    interface->orange = al_load_bitmap("./orange.png");
    interface->yellow = al_load_bitmap("./yellow.png");
    interface->green  = al_load_bitmap("./green.png");
    interface->blue   = al_load_bitmap("./blue.png");
    interface->purple = al_load_bitmap("./purple.png");

    interface->bg     = al_load_bitmap("./w141_bg.jpg");
    interface->field  = al_load_bitmap("./back.png");

    interface->redStrip1    = al_load_bitmap("./redStrip1.png");
    interface->redStrip2    = al_load_bitmap("./redStrip2.png");
    interface->redWrap      = al_load_bitmap("./redWrap.png");
    interface->orangeStrip1 = al_load_bitmap("./orangeStrip1.png");
    interface->orangeStrip2 = al_load_bitmap("./orangeStrip2.png");
    interface->orangeWrap   = al_load_bitmap("./orangeWrap.png");
    interface->yellowStrip1 = al_load_bitmap("./yellowStrip1.png");
    interface->yellowStrip2 = al_load_bitmap("./yellowStrip2.png");
    interface->yellowWrap   = al_load_bitmap("./yellowWrap.png");
    interface->greenStrip1  = al_load_bitmap("./greenStrip1.png");
    interface->greenStrip2  = al_load_bitmap("./greenStrip2.png");
    interface->greenWrap    = al_load_bitmap("./greenWrap.png");
    interface->blueStrip1   = al_load_bitmap("./blueStrip1.png");
    interface->blueStrip2   = al_load_bitmap("./blueStrip2.png");
    interface->blueWrap     = al_load_bitmap("./blueWrap.png");
    interface->purpleStrip1 = al_load_bitmap("./purpleStrip1.png");
    interface->purpleStrip2 = al_load_bitmap("./purpleStrip2.png");
    interface->purpleWrap   = al_load_bitmap("./purpleWrap.png");
    interface->choclolate   = al_load_bitmap("./chocolate.png");

}

void interfacedestroy(image* interface)
{
    al_destroy_bitmap(interface->red);
    al_destroy_bitmap(interface->orange);
    al_destroy_bitmap(interface->yellow);
    al_destroy_bitmap(interface->green);
    al_destroy_bitmap(interface->blue);
    al_destroy_bitmap(interface->purple);
    al_destroy_bitmap(interface->bg);
    al_destroy_bitmap(interface->field);
    al_destroy_bitmap(interface->redStrip1);
    al_destroy_bitmap(interface->redStrip2);
    al_destroy_bitmap(interface->redWrap);
    al_destroy_bitmap(interface->orangeStrip1);
    al_destroy_bitmap(interface->orangeStrip2);
    al_destroy_bitmap(interface->orangeWrap);
    al_destroy_bitmap(interface->yellowStrip1);
    al_destroy_bitmap(interface->yellowStrip2);
    al_destroy_bitmap(interface->yellowWrap);
    al_destroy_bitmap(interface->greenStrip1);
    al_destroy_bitmap(interface->greenStrip2);
    al_destroy_bitmap(interface->greenWrap);
    al_destroy_bitmap(interface->blueStrip1);
    al_destroy_bitmap(interface->blueStrip2);
    al_destroy_bitmap(interface->blueWrap);
    al_destroy_bitmap(interface->purpleStrip1);
    al_destroy_bitmap(interface->purpleStrip2);
    al_destroy_bitmap(interface->purpleWrap);
    al_destroy_bitmap(interface->choclolate);

    al_destroy_display(interface->display);
}

void interfaceShow(image* interface, candy* Map,int COL, int ROW)
{
    int i,j;

    al_draw_bitmap(interface->bg, 0, 0, 0);
    al_draw_bitmap(interface->field, 31, 31, 0);

    al_rest(0.2);

    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            if(Map[COL*i+j].color==0)
                al_draw_bitmap(interface->none, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);

            else if(Map[COL*i+j].color==1)
            {
                if(Map[COL*i+j].property==1)
                    al_draw_bitmap(interface->redStrip1, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else if(Map[COL*i+j].property==2)
                    al_draw_bitmap(interface->redStrip2, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else if(Map[COL*i+j].property==3)
                    al_draw_bitmap(interface->redWrap, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else
                    al_draw_bitmap(interface->red, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
            }

            else if(Map[COL*i+j].color==2)
            {
                if(Map[COL*i+j].property==1)
                    al_draw_bitmap(interface->orangeStrip1, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else if(Map[COL*i+j].property==2)
                    al_draw_bitmap(interface->orangeStrip2, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else if(Map[COL*i+j].property==3)
                    al_draw_bitmap(interface->orangeWrap, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else
                    al_draw_bitmap(interface->orange, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
            }
            else if(Map[COL*i+j].color==3)
            {
                if(Map[COL*i+j].property==1)
                    al_draw_bitmap(interface->yellowStrip1, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else if(Map[COL*i+j].property==2)
                    al_draw_bitmap(interface->yellowStrip2, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else if(Map[COL*i+j].property==3)
                    al_draw_bitmap(interface->yellowWrap, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else
                    al_draw_bitmap(interface->yellow, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
            }
            else if(Map[COL*i+j].color==4)
            {
                if(Map[COL*i+j].property==1)
                    al_draw_bitmap(interface->greenStrip1, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else if(Map[COL*i+j].property==2)
                    al_draw_bitmap(interface->greenStrip2, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else if(Map[COL*i+j].property==3)
                    al_draw_bitmap(interface->greenWrap, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else
                    al_draw_bitmap(interface->green, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
            }
            else if(Map[COL*i+j].color==5)
            {
                if(Map[COL*i+j].property==1)
                    al_draw_bitmap(interface->blueStrip1, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else if(Map[COL*i+j].property==2)
                    al_draw_bitmap(interface->blueStrip2, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else if(Map[COL*i+j].property==3)
                    al_draw_bitmap(interface->blueWrap, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else
                    al_draw_bitmap(interface->blue, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
            }
            else if(Map[COL*i+j].color==6)
            {
                if(Map[COL*i+j].property==1)
                    al_draw_bitmap(interface->purpleStrip1, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else if(Map[COL*i+j].property==2)
                    al_draw_bitmap(interface->purpleStrip2, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else if(Map[COL*i+j].property==3)
                    al_draw_bitmap(interface->purpleWrap, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
                else
                    al_draw_bitmap(interface->purple, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
            }
            else
                al_draw_bitmap(interface->choclolate, ((DISPLAY_WIDTH-(COL*50))/2)+j*50, ((DISPLAY_HEIGHT-(ROW*50))/2)+i*50, 0);
        }
        al_flip_display();
    }
}
int interfaceSwap(image* interface, candy* Map, int swap1[2], int swap2[2],int COL, int ROW)
{
    int i,j;
    ALLEGRO_MOUSE_STATE msestate;

    while(1)
    {
        al_get_mouse_state(&msestate);
        // printf("%d\t",msestate.x );
        // printf("%d\n",msestate.y );

        if(al_mouse_button_down(&msestate,1))
        {

            for(i=0; i<ROW; i++)
            {
                for(j=0; j<COL; j++)
                {
                    if(msestate.x >=(((DISPLAY_WIDTH-(COL*50))/2)+(j*50))&&msestate.x <=(((DISPLAY_WIDTH-(COL*50))/2)+((j+1)*50))&&msestate.y >=(((DISPLAY_HEIGHT-(ROW*50))/2)+(i*50))&&msestate.y<=(((DISPLAY_HEIGHT-(ROW*50))/2)+((i+1)*50)))
                    {

                        swap1[0]=i ;
                        swap1[1]=j;
                        printf("%d  %d",swap1[0],swap1[1]);
                        while(1)
                        {
                            al_get_mouse_state(&msestate);
                            if(!al_mouse_button_down(&msestate,1))
                            {
                                for(i=0; i<ROW; i++)
                                {
                                    for(j=0; j<COL; j++)
                                    {
                                        if(msestate.x>=(((DISPLAY_WIDTH-(COL*50))/2)+(j*50))&&msestate.x<=(((DISPLAY_WIDTH-(COL*50))/2)+((j+1)*50))&&msestate.y >=(((DISPLAY_HEIGHT-(ROW*50))/2)+(i*50))&&msestate.y<=(((DISPLAY_HEIGHT-(ROW*50))/2)+((i+1)*50)))
                                        {

                                            swap2[0]=i ;
                                            swap2[1]=j;
                                            printf("%d  %d",swap2[0],swap2[1]);
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    }
    return 0;
}
