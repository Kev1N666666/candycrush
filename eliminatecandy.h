#pragma once

#include "map.h"

/**map eliminate relative function**/
int candyEliminate(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate);
int candyEliminate5Above(candy *Map, int candynumber, int candytype, int chocolate, int* Swap1, int* Swap2, int ROW, int COL);
int candyEliminate3(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate);
int candyEliminatechocolate(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate);
int candyEliminate4(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate);
int candyEliminate_LT(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate);
void fall_down(candy *Map, int candytype, int row, int col);
int *create_matrix1(int cols);
candy *create_matrix2(int rows, int cols);
int eliminateStripeCandy(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate);
int eliminateSpecialCandy(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate);
int eliminateWrappedCandy(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate);
int eliminateStripeAndWrap(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate);
int eliminateWrapAndWrap(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate);
int eliminateChocolate(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate);
int eliminateChocoAndChoco(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate);
int eliminateStripeAndStrip(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate);


