#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "map.h"
#include "interface.h"
#include "eliminatecandy.h"

/**Please read Readme.txt**/

/**
* contribute
         kevin Wu
         XiangJun Yang
 
*
* 
 
 **/
int main(int argc, char *argv[])
{
    int turn=20;//strtol(argv[1], NULL, 10);
    int target=1500;//strtol(argv[2], NULL, 10);
    int ROW=9;//strtol(argv[3], NULL, 10);
    int COL=9;//strtol(argv[4], NULL, 10);
    int candytype=6;//strtol(argv[5], NULL, 10);
    int *swap1,*swap2;
    int prescore;
    int score=0;

    if(candytype>6 || candytype<2)
        return 0;

    candy* Map;
    Map=create_candy(ROW,COL);

    swap1=create_int_matrix1(2);
    swap2=create_int_matrix1(2);

    image interface;

    al_init();
    al_init_primitives_addon();
    al_install_mouse();
    al_init_image_addon();
    interfaceSet(&interface);
    al_register_event_source(interface.alEventQueue, al_get_mouse_event_source());



    mapInitial(Map,ROW,COL,swap1,swap2,candytype,10);

    mapPrint(Map,turn,score,ROW,COL);
    interfaceShow(&interface,Map,COL,ROW);
    printf("this is Rxiang\n");

    while(turn != 0 && score < target)
    {


        swap1[0]=-1;
        swap1[1]=-2;
        swap2[0]=-3;
        swap2[1]=-4;

        interfaceSwap(&interface,Map,swap1,swap2,COL,ROW);
        swapPosition(Map,swap1,swap2,COL);
        turn--;

        mapPrint(Map,turn,score,ROW,COL);
        interfaceShow(&interface,Map,COL,ROW);

        prescore=score;
        score=score+candyEliminate(Map,ROW,COL,swap1,swap2,candytype,10);
        fall_down(Map,candytype,ROW,COL);

        if(score == prescore)
        {
            printf("WRONG MOVING!!\n");
            swapPosition(Map,swap1,swap2,COL);
            turn++;

            mapPrint(Map,turn,score,ROW,COL);
            interfaceShow(&interface,Map,COL,ROW);
        }
        else
        {
            swap1[0]=0;
            swap1[1]=-1;
            swap2[0]=-1;
            swap2[1]=0;

            while(score!=prescore)
            {
                prescore=score;
                score=score+candyEliminate(Map,ROW,COL,swap1,swap2,candytype,10);
                fall_down(Map,candytype,ROW,COL);
            }

            mapPrint(Map,turn,score,ROW,COL);
            interfaceShow(&interface,Map,COL,ROW);

        }
    }
    interfacedestroy(&interface);

    if(turn== 0 && score<target)
    {

        printf("    GAME OVER!!   \n");

        system("pause");

        return 0;
    }



    DataRankOutput(score,turn);

    free(Map);
    free(swap1);
    free(swap2);

    return 0;

}
