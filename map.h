#pragma once

#include "rankData.h"

typedef struct candy
{
    int color;
    int property;
} candy;

/**map calculate relative function**/
void mapInitial(candy* Map,int ROW,int COL,int* Swap1,int* Swap2,int candytype, int chocolate);
void mapPrint(candy* Map, int turn, int score, int ROW, int COL);
void swapPosition(candy* Map,int* swap1,int* swap2, int COL);
void bubble_sort(rankData Rank[], int n);
void fall_down(candy *Map, int candytype, int row, int col);
int *create_int_matrix1(int cols);
candy* create_candy();










