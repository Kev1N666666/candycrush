#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "map.h"
#include "rankData.h"
#include "eliminatecandy.h"

void mapInitial(candy* Map,int ROW,int COL,int* Swap1,int* Swap2,int candytype, int chocolate)
{
    int i,j, score=1;
    srand(time(NULL));

    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            Map[COL*i+j].color= rand()%candytype+1;;
        }
    }

    while(score!=0)
    {
        score=candyEliminate3(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);
        fall_down(Map,candytype,ROW,COL);
    }
}

void mapPrint(candy* Map, int turn, int score, int ROW, int COL)
{
    int i,j;

    printf("\n   remain:%d   grade:%d\n",turn,score);
    printf("\n");
    printf("    0 1 2 3 4 5 6 7 8\n");
    printf("    -----------------\n");
    for(i=0; i<ROW; i++)
    {
        printf("%d | ",i);
        for(j=0; j<COL; j++)
        {
            printf("%d ",Map[COL*i+j].color);
        }
        printf("\n");
    }
    printf("\n");

    printf("    0 1 2 3 4 5 6 7 8\n");
    printf("    -----------------\n");
    for(i=0; i<ROW; i++)
    {
        printf("%d | ",i);
        for(j=0; j<COL; j++)
        {
            printf("%d ",Map[COL*i+j].property);
        }
        printf("\n");
    }
    printf("\n");
}

void swapPosition(candy* Map,int* swap1,int* swap2, int COL)
{
    int exchange;
    exchange = Map[COL*swap1[0]+swap1[1]].color;
    Map[COL*swap1[0]+swap1[1]].color = Map[COL*swap2[0]+swap2[1]].color;
    Map[COL*swap2[0]+swap2[1]].color = exchange;

    exchange = Map[COL*swap1[0]+swap1[1]].property;
    Map[COL*swap1[0]+swap1[1]].property = Map[COL*swap2[0]+swap2[1]].property;
    Map[COL*swap2[0]+swap2[1]].property = exchange;
}

void bubble_sort(rankData Rank[], int n)
{
    rankData temp;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (Rank[j].score < Rank[i].score)
            {
                temp = Rank[j];
                Rank[j] = Rank[i];
                Rank[i] = temp;
            }
        }
    }
}

void DataRankOutput(int score, int turn)
{
    int i=0,j;

    char name[15];
    char sdate[9];
    char stime[9];
    char data[256];

    rankData Rank[50];

    FILE* list;
    list= fopen("rank.txt","a+");

    score= score + turn*100;
    printf("please enter your name:");
    scanf( "%s",name);
    printf("\n");

    _strdate(sdate);
    _strtime(stime);

    sprintf(data,"%d %s  %s  %s\n", score, name, sdate, stime);
    printf("%s\n\n",data);
    fprintf(list,"%s",data);
    fclose(list);

    list= fopen("rank.txt","a+");
    while(!feof(list))
    {
        fscanf(list,"%d %s  %s  %s\n",&Rank[i].score,Rank[i].name,Rank[i].sdate,Rank[i].stime);
        sprintf(Rank[i].data,"%d %s  %s  %s\n",Rank[i].score,Rank[i].name,Rank[i].sdate,Rank[i].stime);

        i++;
    }
    fclose(list);

    list= fopen("rank.txt","w+");
    bubble_sort(Rank,i);

    for(j=0; j<i; j++)
    {
        fprintf(list,"%s",Rank[j].data);
        printf("NO.%d  %s",j+1,Rank[j].data);
    }
    fclose(list);
}

void fall_down(candy *Map, int candytype, int row, int col)
/* let the number 0 get to the top of the matrix
   and change the property at the same time */
{
    int	i, j, k, *swap1,*swap2;

    swap1=create_int_matrix1(2);
    swap2=create_int_matrix1(2);

    srand(time(NULL));

    for (k= 0; k < row; k ++)//run the function nine times to get the result
    {
        for (i= 0; i < row; i ++ )
        {
            for (j = 0; j < col; j ++)
            {
                if (Map[col*i+j].color == 0)
                {
                    if (i==0)//if the top of the col is 0 , convert it to be random number
                    {
                        Map[col*i+j].color = rand()%candytype +1;
                    }
                    else//if not 0 ,just change the position
                    {
                        swap1[0]=i;
                        swap1[1]=j;
                        swap2[0]=i-1;
                        swap2[1]=j;

                        swapPosition(Map,swap1,swap2,col);
                    }
                }
            }
        }
    }

    free(swap1);
    free(swap2);
}

int *create_int_matrix1(int cols)
{
// input number of elements (cols)
// output a pointer to 1D (vector) mat[cols]

    int *mat = (int *) calloc(cols,sizeof(int));

    return mat;
}

candy* create_candy(int row, int col)
{
    candy *mat = (candy *) calloc(row*col,sizeof(candy));

    return mat;
}




