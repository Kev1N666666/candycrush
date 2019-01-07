#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "eliminatecandy.h"

int candyEliminate_LT(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate)
//input pointer map
//output grade
{
    int j,k;

    int grade = 0;

    for(j=0; j<ROW-2; j++)          //first type of L   L1
    {
        for(k=0; k<COL-2; k++)
        {
            if(1 == Map[COL*j+k].color || Map[COL*j+k].color == 2 || Map[COL*j+k].color == 3 || Map[COL*j+k].color == 4 || Map[COL*j+k].color == 5)  //determine type of candy
            {
                if(Map[COL*j+k] . color == Map[COL*j+k+1] . color && Map[COL*j+k+1] . color == Map[COL*j+k+2] . color && Map[COL*j+k] . color == Map[COL*(j+1)+k] . color && Map[COL*(j+1)+k] . color == Map[COL*(j+2)+k] . color)
                    //determine whether the content of target is same or not
                {
                    if(Map[COL*j+k-1] . color == Map[COL*j+k] . color && k>0)   //first extension  of L1
                    {
                        Map[COL*j+k-1] . color=0;                             //clear content of extension
                        grade+=40;                                          //return grade
                    }
                    if(Map[COL*(j-1)+k] . color == Map[COL*j+k] . color && j>0)   //second extension  of L1
                    {
                        Map[COL*(j-1)+k] . color=0;                             //clear content of extension
                        grade+=40;                                          //return grade
                    }
                    Map [COL*j+k+1]. color=Map[COL*j+k+2] . color=Map[COL*(j+1)+k] . color=Map[COL*(j+2)+k] . color=0;//clear content of target
                    Map[COL*j+k] . property=3;//product a wrapped candy
                    grade+=200;//return grade
                }
            }
        }
    }
    for(j=0; j<ROW-2; j++)          //second type of L
    {
        for(k=2; k<COL; k++)
        {
            if(1 == Map[COL*j+k] . color || Map[COL*j+k] . color == 2 || Map[COL*j+k] . color == 3 || Map[COL*j+k] . color == 4 || Map[COL*j+k] . color == 5)  //determine type of candy
            {
                if(Map[COL*j+k].color == Map[COL*j+k-1] . color && Map[COL*j+k-1] . color == Map[COL*j+k-2] . color && Map[COL*j+k] . color == Map[COL*(j+1)+k] . color && Map[COL*(j+1)+k] . color == Map[COL*(j+2)+k] . color)
                    //determine whether the content of target is same or not
                {

                    if(Map[COL*j+k+1] . color == Map[COL*j+k] . color && k<COL-1)   //first extension  of L2
                    {
                        Map[COL*j+k+1] . color=0;                                 //clear content of extension
                        grade+=40;                                              //return grade
                    }
                    if(Map[COL*(j-1)+k] . color == Map[COL*j+k] . color && j>0)    //second extension  of L2
                    {
                        Map[COL*(j-1)+k] . color=0;                              //clear content of extension
                        grade+=40;                                           //return grade
                    }
                    Map[COL*j+k-1] . color=Map[COL*j+k-2] . color=Map[COL*(j+1)+k] . color=Map[COL*(j+2)+k] . color=0;//clear content of target
                    Map[COL*j+k] . property=3;//product a wrapped candy
                    grade+=200;                                              //return grade
                }
            }
        }
    }
    for(j=2; j<ROW; j++)            //third type of L
    {
        for(k=2; k<COL; k++)
        {
            if(1 == Map[COL*j+k] . color || Map[COL*j+k] . color == 2 || Map[COL*j+k] . color == 3 || Map[COL*j+k] . color == 4 || Map[COL*j+k] . color == 5)  //determine type of candy
            {
                if(Map[COL*j+k] . color == Map[COL*j+k-1] . color && Map[COL*j+k-1] . color == Map[COL*j+k-2] . color && Map[COL*j+k] . color == Map[COL*(j-1)+k] . color && Map[COL*(j-1)+k] . color == Map[COL*(j-2)+k] . color)
                    //determine whether the content of target is same or not
                {
                    if(Map[COL*j+k+1] . color == Map[COL*j+k] . color && k<COL-1)   //first extension  of L3
                    {
                        Map[COL*j+k+1] . color=0;                                 //clear content of extension
                        grade+=40;                                              //return grade
                    }
                    if(Map[COL*(j+1)+k] . color == Map[COL*j+k] . color && j<ROW-1)   //second extension  of L3
                    {
                        Map[COL*(j+1)+k] . color=0;                                 //clear content of extension
                        grade+=40;                                              //return grade
                    }
                    Map[COL*j+k-1] . color=Map[COL*j+k-2] . color=Map[COL*(j-1)+k] . color=Map[COL*(j-2)+k] . color=0;//clear content of target
                    Map[COL*j+k] . property=3;//product a wrapped candy
                    grade+=200;                                            //return grade
                }
            }
        }
    }
    for(j=2; j<ROW; j++)            //fourth type of L
    {
        for(k=0; k<COL-2; k++)
        {
            if(1 == Map[COL*j+k] . color || Map[COL*j+k] . color == 2 || Map[COL*j+k] . color == 3 || Map [COL*j+k]. color == 4 || Map[COL*j+k] . color == 5)  //determine type of candy
            {
                if(Map[COL*j+k] . color == Map[COL*j+k+1] . color && Map[COL*j+k+1] . color == Map[COL*j+k+2] . color && Map[COL*j+k] . color == Map[COL*(j-1)+k] . color && Map[COL*(j-1)+k] . color == Map[COL*(j-2)+k] . color)
                    //determine whether the content of target is same or not
                {
                    if(Map[COL*j+k-1] . color == Map[COL*j+k] . color && k>0)   //first extension  of L4
                    {
                        Map[COL*j+k+1] . color=0;                             //clear content of extension
                        grade+=40;                                          //return grade
                    }
                    if(Map[COL*(j+1)+k] . color == Map[COL*j+k] . color && j<ROW-1)//second extension  of L4
                    {
                        Map[COL*(j+1)+k] . color=0;                             //clear content of extension
                        grade+=40;                                          //return grade
                    }
                    Map[COL*j+k+1] . color=Map[COL*j+k+2] . color=Map[COL*(j-1)+k] . color=Map[COL*(j-2)+k] . color=0;//clear content of target
                    Map[COL*j+k] . property=3;//product a wrapped candy
                    grade+=200;                                              //return grade
                }
            }
        }
    }
    for(j=1; j<ROW-1; j++)      //first type of T
    {
        for(k=0; k<COL-2; k++)
        {
            if(1 == Map[COL*j+k] . color || Map[COL*j+k] . color == 2 || Map[COL*j+k] . color == 3 || Map[COL*j+k] . color == 4 || Map[COL*j+k] . color == 5)  //determine type of candy
            {
                if(Map[COL*j+k] . color == Map[COL*j+k+1] . color && Map[COL*j+k+1] . color == Map[COL*j+k+2] . color && Map[COL*j+k] . color == Map[COL*(j-1)+k] . color && Map[COL*(j-1)+k] . color == Map[COL*(j+1)+k] . color)
                    //determine whether the content of target is same or not
                {
                    Map[COL*j+k+1] . color=Map[COL*j+k+2] . color=Map[COL*(j-1)+k] . color=Map[COL*(j+1)+k] . color=0;//clear content of target
                    Map[COL*j+k] . property=3;//product a wrapped candy
                    grade+=200;                                          //return grade
                }
            }
        }
    }
    for(j=0; j<ROW-2; j++)      //second type of T
    {
        for(k=1; k<COL-1; k++)
        {
            if(1 == Map[COL*j+k] . color || Map[COL*j+k] . color == 2 || Map[COL*j+k] . color == 3 || Map[COL*j+k] . color == 4 || Map[COL*j+k] . color == 5)  //determine type of candy
            {
                if(Map[COL*j+k] . color == Map[COL*j+k-1] . color && Map[COL*j+k-1] . color == Map[COL*j+k+1] . color && Map[COL*j+k] . color == Map[COL*(j+1)+k] . color && Map[COL*(j+1)+k] . color == Map[COL*(j+2)+k] . color)
                    //determine whether the content of target is same or not
                {
                    Map[COL*j+k-1] . color=Map[COL*j+k+1] . color=Map[COL*(j+1)+k] . color=Map[COL*(j+2)+k] . color=0;//clear content of target
                    Map[COL*j+k] . property=3;//product a wrapped candy
                    grade+=200;                                          //return grade
                }
            }
        }
    }
    for(j=1; j<ROW-1; j++)      //third type of T
    {
        for(k=2; k<COL; k++)
        {
            if(1 == Map[COL*j+k] . color || Map[COL*j+k] . color == 2 || Map[COL*j+k] . color == 3 || Map[COL*j+k] . color == 4 || Map[COL*j+k] . color == 5)  //determine type of candy
            {
                if(Map[COL*j+k] . color == Map [COL*j+k-1]. color && Map[COL*j+k-1] . color == Map[COL*j+k-2] . color && Map[COL*j+k] . color == Map[COL*(j-1)+k] . color && Map[COL*(j-1)+k] . color == Map[COL*(j+1)+k] . color)
                    //determine whether the content of target is same or not
                {
                    Map[COL*j+k-1] . color=Map [COL*j+k-2]. color=Map[COL*(j-1)+k] . color=Map[COL*(j+1)+k] . color=0;//clear content of target
                    Map[COL*j+k] . property=3;//product a wrapped candy
                    grade+=200;                                          //return grade
                }
            }
        }
    }
    for(j=2; j<ROW; j++)        //fourth type of T
    {
        for(k=1; k<COL-1; k++)
        {
            if(1 == Map[COL*j+k] . color || Map[COL*j+k] . color == 2 || Map[COL*j+k] . color == 3 || Map[COL*j+k] . color == 4 || Map[COL*j+k] . color == 5)  //determine type of candy
            {
                if(Map[COL*j+k] . color == Map[COL*j+k-1] . color && Map[COL*j+k-1] . color == Map[COL*j+k+1] . color && Map[COL*j+k] . color == Map[COL*(j-1)+k] . color && Map[COL*(j-1)+k] . color == Map[COL*(j-2)+k] . color)
                    //determine whether the content of target is same or not
                {
                    Map[COL*j+k-1] . color=Map[COL*j+k+1] . color=Map[COL*(j-1)+k] . color=Map[COL*(j-2)+k] . color=0;//clear content of target
                    Map[COL*j+k] . property=3;//product a wrapped candy
                    grade+=200;                                          //return grade
                }
            }
        }
    }

    grade+=eliminateSpecialCandy(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);//process special kind of candy


    return grade; //return grade
}

int candyEliminate(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate)
{
    int grade=0;

    grade+=eliminateChocoAndChoco(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);
    grade+=eliminateStripeAndWrap(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);//eliminate wrapped with stripe candy
    grade+=eliminateWrapAndWrap(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);
    grade+=eliminateStripeAndStrip(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);
    grade+=candyEliminatechocolate(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);

    grade+=candyEliminate5Above(Map,5,candytype,chocolate,Swap1,Swap2,ROW,COL);
    grade+=candyEliminate_LT(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);
    grade+=candyEliminate4(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);
    grade+=candyEliminate3(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);


    return grade;
}
int candyEliminate5Above(candy *Map, int candynumber, int candytype, int chocolate, int* Swap1, int* Swap2, int ROW, int COL)
{
    int i, j, k, l, m, flag, equalflag, grade=0,weigh=10*(candynumber-1);

    if(candynumber<5)
        return 0;

    for(i=0; i<ROW; i++)//column counting
    {
        for(j=0; j<COL-candynumber+1; j++)//row counting
        {
            flag=0;

            for(k=1; k<=candytype; k++)//檢查是否符合消除範圍
            {
                if(Map[COL*i+j].color==k)
                    flag++;
            }

            if(flag)//符合消除範圍
            {
                equalflag=0;

                for(l=0; l<candynumber-1; l++)
                {
                    if(Map[COL*i+j+l].color==Map[COL*i+j+l+1].color)//檢查相同個數
                        equalflag++;
                }

                if(equalflag==candynumber-1)//符合相同個數
                {
                    if((Swap1[0]==i && Swap1[1]==j+2) || (Swap2[0]==i && Swap2[1]==j+2))//檢查第一個交換的位置有無在被消掉之內
                    {
                        if(Map[COL*(i-1)+j+2].color == Map[COL*i+j].color && Map[COL*(i+1)+j+2].color == Map[COL*i+j].color && i-1 >= 0 && i+1 <=ROW-1)//是否有延伸
                        {
                            Map[COL*(i-1)+j+2].color = Map[COL*(i+1)+j+2].color = 0;//消除延伸
                        }
                        if(Map[COL*(i-2)+j+2].color == Map[COL*i+j].color && Map[COL*(i-1)+j+2].color == Map[COL*i+j].color && i-2 >= 0)//是否有延伸
                        {
                            Map[COL*(i-2)+j+2].color = Map[COL*(i-1)+j+2].color = 0;//消除延伸
                        }
                        if(Map[COL*(i+2)+j+2].color == Map[COL*i+j].color && Map[COL*(i+1)+j+2].color == Map[COL*i+j].color && i+2 <= ROW-1)//是否有延伸
                        {
                            Map[COL*(i+2)+j+2].color = Map[COL*(i+1)+j+2].color = 0;//消除延伸
                        }
                        for(m=0; m<candynumber; m++)
                        {
                            Map[COL*i+j+m].color=0;//消除內容
                        }
                        Map[COL*i+j+2].color=chocolate;//在交換位置產生巧克力
                        Map[COL*i+j+2].property=chocolate;

                        grade+=weigh*7;//計分
                    }
                    else//天降產生巧克力
                    {
                        for(m=0; m<candynumber; m++)
                        {
                            if(Map[COL*(i-2)+j+m].color == Map[COL*i+j+m].color && Map[COL*(i-1)+j+m].color == Map[COL*i+j+m].color && i-2 >= 0)//是否有延伸
                            {
                                Map[COL*(i-2)+j+m].color = Map[COL*(i-1)+j+m].color = 0;//消除延伸
                                grade+=weigh*2;//計分
                            }
                            if(Map[COL*(i+2)+j+m].color == Map[COL*i+j+m].color && Map[COL*(i+1)+j+m].color == Map[COL*i+j+m].color && i+2 <= ROW-1)//是否有延伸
                            {
                                Map[COL*(i+2)+j+m].color = Map[COL*(i+1)+j+m].color = 0;//消除延伸
                                grade+=weigh*2;//計分
                            }
                        }

                        Map[COL*i+j].color=chocolate;//在最左邊產生巧克力
                        Map[COL*i+j].property=chocolate;

                        for(m=1; m<candynumber; m++)
                        {
                            Map[COL*i+j+m].color=0;//消除內容
                        }

                        grade+=weigh*5;//計分
                    }
                }
            }
        }
    }

    for(j=0; j<COL; j++)//行計數
    {
        for(i=0; i<ROW-candynumber+1; i++)//列計數
        {
            flag=0;
            for(k=1; k<=candytype; k++)
            {
                if(Map[COL*i+j].color==k)//檢查是否符合消除範圍
                    flag++;
            }

            if(flag)//符合消除範圍
            {
                equalflag=0;
                for(l=0; l<candynumber-1; l++)
                {
                    if(Map[COL*(i+l)+j].color==Map[COL*(i+l+1)+j].color)//檢查相同個數
                        equalflag++;
                }

                if(equalflag==candynumber-1)//符合相同個數
                {
                    if((Swap1[0]==i+2 && Swap1[1]==j) || (Swap2[0]==i+2 && Swap2[1]==j))//檢查第一個交換的位置有無在被消掉之內
                    {
                        if(Map[COL*(i+2)+j-1].color == Map[COL*i+j].color && Map[COL*(i+2)+j+1].color == Map[COL*i+j].color && j-1 >= 0 && j+1 <=COL-1)//是否有延伸
                        {
                            Map[COL*(i+2)+j-1].color = Map[COL*(i+2)+j+1].color = 0;//消除延伸
                        }
                        if(Map[COL*(i+2)+j-2].color == Map[COL*i+j].color && Map[COL*(i+2)+j-1].color == Map[COL*i+j].color && j-2 >= 0)//是否有延伸
                        {
                            Map[COL*(i+2)+j-2].color = Map[COL*(i+2)+j-1].color = 0;//消除延伸
                        }
                        if(Map[COL*(i+2)+j+2].color == Map[COL*i+j].color && Map[COL*(i+2)+j+1].color == Map[COL*i+j].color && j+2 <= COL-1)//是否有延伸
                        {
                            Map[COL*(i+2)+j+2].color = Map[COL*(i+2)+j+1].color = 0;//消除延伸
                        }
                        for(m=0; m<candynumber; m++)
                        {
                            Map[COL*(i+m)+j].color=0;//消除內容
                        }
                        Map[COL*(i+2)+j].color=chocolate;//在交換位置產生巧克力
                        Map[COL*(i+2)+j].property=chocolate;

                        grade+=weigh*7;//計分
                    }
                    else
                    {
                        for(m=0; m<candynumber; m++)
                        {
                            if(Map[COL*(i+m)+j-1].color == Map[COL*(i+m)+j].color && Map[COL*(i+m)+j-2].color == Map[COL*(i+m)+j].color && j-2 >= 0)//是否有延伸
                            {
                                Map[COL*(i+m)+j-1].color = Map[COL*(i+m)+j-2].color = 0;//消除延伸
                                grade+=weigh*2;//計分
                            }
                            if(Map[COL*(i+m)+j+2].color == Map[COL*(i+m)+j].color && Map[COL*(i+m)+j+1].color == Map[COL*(i+m)+j].color && j+2 <= COL-1)//是否有延伸
                            {
                                Map[COL*(i+m)+j+2].color = Map[COL*(i+m)+j+1].color = 0;//消除延伸
                                grade+=weigh*2;//計分
                            }
                        }

                        Map[COL*i+j].color=chocolate;//在最左邊產生巧克力
                        Map[COL*i+j].property=chocolate;

                        for(m=1; m<candynumber; m++)
                        {
                            Map[COL*(i+m)+j].color=0;//消除內容
                        }

                        grade+=weigh*7;//計分
                    }
                }
            }
        }
    }

    grade+=eliminateSpecialCandy(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);//process special kind of candy


    return grade;//傳回分數
}

int eliminateSpecialCandy(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate)
//input a structure candy process specially kind of candy
//output a grade
{
    int grade=0, i, j, flag=0;

    for(i=0; i<ROW; i++)//inspect if any special candy need to be eliminated
    {
        for(j=0; j<COL; j++)
        {
            if(Map[COL*i+j].color==0 && Map[COL*i+j].property!=0)
            {
                flag++;
            }
        }
    }

    if(flag==0)
        return 0;

    grade+=eliminateStripeCandy(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);//eliminate stripe candy
    grade+=eliminateWrappedCandy(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);//eliminate wrapped candy
    grade+=eliminateChocolate(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);//eliminate chocolate

    return grade;
}

int eliminateStripeCandy(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate)
//input a structure candy to eliminate stripe candies
//output a grade
{
    int i, j, k, grade=0, flag=0;

    for(i=0; i<ROW; i++)//eliminate vertically stripe candy
    {
        for(j=0; j<COL; j++)
        {
            if(Map[COL*i+j].color==0 && Map[COL*i+j].property==1)//inspect if a special need to be eliminated
            {
                Map[COL*i+j].property=0;//eliminate the property of candy

                for(k=0; k<ROW; k++)
                {
                    if(Map[COL*k+j].color != 0)//get rid of candy had eliminated
                    {
                        Map[COL*k+j].color=0;//clear
                        flag++;//count number of eliminated candy
                    }

                    grade+=eliminateSpecialCandy(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);//process loop eliminate
                }

            }
        }
    }

    for(i=0; i<ROW; i++)//eliminate parallel stripe candy
    {
        for(j=0; j<COL; j++)
        {
            if(Map[COL*i+j].color==0 && Map[COL*i+j].property==2)//inspect if a special need to be eliminated
            {
                Map[COL*i+j].property=0;//eliminate the property of candy

                for(k=0; k<ROW; k++)
                {
                    if(Map[COL*i+k].color != 0)//get rid of candy had eliminated
                    {
                        Map[COL*i+k].color=0;//clear
                        flag++;//count number of eliminated candy
                    }

                    grade+=eliminateSpecialCandy(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);//process loop eliminate
                }

            }
        }
    }

    grade+=flag*30;//plus grade


    return grade;
}

int eliminateChocolate(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate)
//input a structure candy to eliminate chocolate
//output a grade
{
    int i, j, grade=0, flag=0, elicolor=rand()%candytype+1;

    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            if(Map[COL*i+j].color==0 && Map[COL*i+j].property==chocolate)//inspect if a special candy need to be eliminated
            {
                Map[COL*i+j].property=0;//eliminate the property of candy

                if(Map[COL*i+j].color==elicolor)
                {
                    Map[COL*i+j].color=0;//clear
                    flag++;//count number of eliminated candy
                }
            }

            grade+=eliminateSpecialCandy(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);//process loop eliminate
        }
    }

    grade+=flag*30;//plus grade


    return grade;
}


int candyEliminate3(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate)
{
    int i, j, k, flag, equalflag, grade = 0;

    for(i=0; i<ROW; i++)//row counting
    {
        for(j=0; j<COL-2; j++)//column counting
        {
            flag=0;

            for(k=1; k<=candytype; k++)//inspect if contents of array is equal to types of candy
            {
                if(Map[COL*i+j].color==k)
                    flag++;
            }

            if(flag)
            {
                equalflag=0;

                for(k=0; k<3-1; k++)
                {
                    if(Map[COL*i+j+k].color==Map[COL*i+j+k+1].color)//inspect number of equivalent candy
                        equalflag++;
                }

                if(equalflag==3-1)
                {
                    for(k=0; k<3; k++)
                    {
                        Map[COL*i+j+k].color=0;//eliminate contents
                    }


                    grade+=60;//plus grade
                }
            }
        }
    }

    for(j=0; j<COL; j++)//row counting
    {
        for(i=0; i<ROW-2; i++)//column counting
        {
            flag=0;

            for(k=1; k<=candytype; k++)//inspect if contents of array is equal to types of candy
            {
                if(Map[COL*i+j].color==k)
                    flag++;
            }

            if(flag)
            {
                equalflag=0;

                for(k=0; k<3-1; k++)
                {
                    if(Map[COL*(i+k)+j].color==Map[COL*(i+k+1)+j].color)//inspect number of equivalent candy
                        equalflag++;
                }

                if(equalflag==3-1)
                {
                    for(k=0; k<3; k++)
                    {
                        Map[COL*(i+k)+j].color=0;//eliminate contents
                    }

                    grade+=60;//plus grade
                }
            }
        }
    }

    grade+=eliminateSpecialCandy(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);//process special kind of candy

    return grade;
}

int candyEliminatechocolate(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate)
{
    int i, j, temp, grade = 0, stripecandy=0,wrappedcandy=0;

    if(Map[COL*Swap1[0]+Swap1[1]].property == chocolate)//inspect if the first position is chocolate
    {
        if(Map[COL*Swap2[0]+Swap2[1]].property==1 || Map[COL*Swap2[0]+Swap2[1]].property==2)//inspect if switched candy is stripe candy
            stripecandy=1;

        if(Map[COL*Swap2[0]+Swap2[1]].property==3)//inspect if switched candy is wrapped candy
            wrappedcandy=1;

        temp=Map[COL*Swap2[0]+Swap2[1]].color;//store the type of second position to eliminate others
        Map[COL*Swap1[0]+Swap1[1]].color=0;
        Map[COL*Swap1[0]+Swap1[1]].property=0;
        Map[COL*Swap2[0]+Swap2[1]].color=0;//clear swapped positions
        grade+=60;//plus grade
    }
    else if(Map[COL*Swap2[0]+Swap2[1]].color == chocolate)//inspect if the second position is chocolate
    {
        if(Map[COL*Swap1[0]+Swap1[1]].property==1 || Map[COL*Swap1[0]+Swap1[1]].property==2)//inspect if switched candy is stripe candy
            stripecandy=1;

        if(Map[COL*Swap1[0]+Swap1[1]].property==3)//inspect if switched candy is wrapped candy
            wrappedcandy=1;

        temp=Map[COL*Swap1[0]+Swap1[1]].color;//store the type of first position to eliminate others
        Map[COL*Swap1[0]+Swap1[1]].color=0;
        Map[COL*Swap2[0]+Swap2[1]].color=0;//clear swapped positions
        Map[COL*Swap2[0]+Swap2[1]].property=0;
        grade+=60;//plus grade
    }

    if(grade != 0)
    {
        for(i=0; i<ROW; i++)//row counting
        {
            for(j=0; j<COL; j++)//column counting
            {
                if(Map[COL*i+j].color == temp)//inspect if positions equal to temp
                {
                    Map[COL*i+j].color = 0;//clear equivalent contents with temp
                    grade+=30;//plus grade

                    if(stripecandy)
                        Map[COL*i+j].property = rand()%2+1;//give candy property

                    if(wrappedcandy)
                        Map[COL*i+j].property = 3;//give candy property
                }
            }
        }
    }

    grade+=eliminateSpecialCandy(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);//process special kind of candy

    return grade;//傳回分數
}

int candyEliminate4(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate)
{
    int i, j, k, grade = 0, flag, equalflag, temp;

    for(i=0; i<ROW; i++)//row counting
    {
        for(j=0; j<COL-3; j++)//column counting
        {
            flag=0;

            for(k=1; k<=candytype; k++)//inspect if contents of array is equal to types of candy
            {
                if(Map[COL*i+j].color==k)
                    flag++;
            }

            if(flag)
            {
                equalflag=0;

                for(k=0; k<4-1; k++)
                {
                    if(Map[COL*i+j+k].color==Map[COL*i+j+k+1].color)//inspect number of equivalent candy
                        equalflag++;
                }

                if(equalflag==4-1)
                {
                    if(Swap1[0]*COL+Swap1[1]==i*COL+j+1 || Swap1[0]*COL+Swap1[1]==i*COL+j+2)
                        //inspect if the first position at the place  eliminated
                    {
                        Map[COL*Swap1[0]+Swap1[1]].property = 1;//product a vertical candy
                        temp=Map[COL*Swap1[0]+Swap1[1]].color;//store the type of candy
                        for(k=0; k<4; k++)
                        {
                            Map[COL*i+j+k].color=0;//clear content
                        }
                        Map[COL*Swap1[0]+Swap1[1]].color=temp;//rewrite content
                        grade+=120;//plus grade
                    }
                    else if(Swap2[0]*COL+Swap2[1]==i*COL+j+1 || Swap2[0]*COL+Swap2[1]==i*COL+j+2)
                        //inspect if the second position at the place  eliminated
                    {
                        Map[COL*Swap2[0]+Swap2[1]].property = 1;//product a vertical candy
                        temp=Map[COL*Swap2[0]+Swap2[1]].color;//store the type of candy
                        for(k=0; k<4; k++)
                        {
                            Map[COL*i+j+k].color=0;//clear content
                        }
                        Map[COL*Swap2[0]+Swap2[1]].color=temp;//rewrite content
                        grade+=120;//plus grade
                    }
                    else//naturally produce vertical candy
                    {
                        Map[COL*i+j].property = 1;//product a vertical candy
                        for(k=1; k<4; k++)
                        {
                            Map[COL*i+j+k].color=0;//clear content
                        }
                        grade+=120;//plus grade
                    }
                }
            }
        }
    }

    for(j=0; j<ROW; j++)//row counting
    {
        for(i=0; i<COL-3; i++)//column counting
        {
            flag=0;

            for(k=1; k<=candytype; k++)//inspect if contents of array is equal to types of candy
            {
                if(Map[COL*i+j].color==k)
                    flag++;
            }

            if(flag)
            {
                equalflag=0;

                for(k=0; k<4-1; k++)
                {
                    if(Map[COL*(i+k)+j].color==Map[COL*(i+k+1)+j].color)//inspect number of equivalent candy
                        equalflag++;
                }

                if(equalflag==4-1)
                {
                    if(Swap1[0]*COL+Swap1[1]==(i+1)*COL+j || Swap1[0]*COL+Swap1[1]==(i+2)*COL+j)
                        //inspect if the first position at the place  eliminated
                    {
                        Map[COL*Swap1[0]+Swap1[1]].property = 2;//product a horizontal candy
                        temp=Map[COL*Swap1[0]+Swap1[1]].color;//store the type of candy
                        for(k=0; k<4; k++)
                        {
                            Map[COL*(i+k)+j].color=0;//clear content
                        }
                        Map[COL*Swap1[0]+Swap1[1]].color=temp;//rewrite content
                        grade+=120;//plus grade
                    }
                    else if(Swap2[0]*COL+Swap2[1]==(i+1)*COL+j || Swap2[0]*COL+Swap2[1]==(i+2)*COL+j)
                        //inspect if the second position at the place  eliminated
                    {
                        Map[COL*Swap2[0]+Swap2[1]].property = 2;//product a horizontal candy
                        temp=Map[COL*Swap2[0]+Swap2[1]].color;//store the type of candy
                        for(k=0; k<4; k++)
                        {
                            Map[COL*(i+k)+j].color=0;//clear content
                        }
                        Map[COL*Swap2[0]+Swap2[1]].color=temp;//rewrite content
                        grade+=120;//plus grade
                    }
                    else//naturally produce vertical candy
                    {
                        Map[COL*i+j].property = 1;//product a vertical candy
                        for(k=1; k<4; k++)
                        {
                            Map[COL*(i+k)+j].color=0;//clear content
                        }
                        grade+=120;//plus grade
                    }
                }
            }
        }
    }

    grade+=eliminateSpecialCandy(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);//process special kind of candy


    return grade;
}


int eliminateWrappedCandy(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate)
//input pointer map
//output a grade
{
    int i, j,k;
    int step,color=0, flag=0;
    int grade=0, pregrade=0;

    for(step=0; step<2; step++)             //step 0 clear 8 and fall
    {
        //step 1 clear 9 and clear wrapped candy
        if(step==1)
        {
            color=7;
        }
        for(i=0; i<ROW; i++)
        {
            for(j=0; j<COL; j++)
            {
                if(Map[COL*i+j].color==color && Map[COL*i+j].property==3)
                {
                    if(step==1)
                    {
                        Map[COL*i+j].color=0;
                        Map[COL*i+j].property=0;        //clear to normal candy
                    }
                    if(i==0 && j==0)                    //the upper left
                    {
                        if(Map[COL*i+j+1].color!=0)
                        {
                            Map[COL*i+j+1].color=0;
                            flag++;
                        }
                        if(Map[COL*(i+1)+j].color!=0)
                        {
                            Map[COL*(i+1)+j].color=0;
                            flag++;
                        }
                        if(Map[COL*(i+1)+j+1].color!=0)
                        {
                            Map[COL*(i+1)+j+1].color=0;
                            flag++;
                        }
                        grade+=flag*60+60;
                    }
                    if(i==0 && j==COL-1)                //the upper right
                    {
                        if(Map[COL*i+j-1].color!=0)
                        {
                            Map[COL*i+j-1].color=0;
                            flag++;
                        }
                        if(Map[COL*(i+1)+j].color!=0)
                        {
                            Map[COL*(i+1)+j].color=0;
                            flag++;
                        }
                        if(Map[COL*(i+1)+j-1].color!=0)
                        {
                            Map[COL*(i+1)+j-1].color=0;
                            flag++;
                        }
                        grade+=flag*60+60;
                    }
                    if(i==ROW-1 && j==0)                //the lower left
                    {
                        if(Map[COL*i+j+1].color!=0)
                        {
                            Map[COL*i+j+1].color=0;
                            flag++;
                        }
                        if(Map[COL*(i-1)+j].color!=0)
                        {
                            Map[COL*(i-1)+j].color=0;
                            flag++;
                        }
                        if(Map[COL*(i-1)+j+1].color!=0)
                        {
                            Map[COL*(i-1)+j+1].color=0;
                            flag++;
                        }
                        grade+=flag*60+60;
                    }
                    if(i==ROW-1 && j==COL-1)            //the lower right
                    {
                        if(Map[COL*i+j-1].color!=0)
                        {
                            Map[COL*i+j-1].color=0;
                            flag++;
                        }
                        if(Map[COL*(i-1)+j].color!=0)
                        {
                            Map[COL*(i-1)+j].color=0;
                            flag++;
                        }
                        if(Map[COL*(i-1)+j-1].color!=0)
                        {
                            Map[COL*(i-1)+j-1].color=0;
                            flag++;
                        }
                        grade+=flag*60+60;
                    }
                    if(i==0 && j>0 && j<COL-1)          //first row without corner
                    {
                        for(k=-1; k<2; k++)
                        {
                            if(Map[COL*i+j+k].color!=0)
                            {
                                Map[COL*i+j+k].color=0;
                                flag++;
                            }
                            if(Map[COL*(i+1)+j+k].color!=0)
                            {
                                Map[COL*(i+1)+j+k].color=0;
                                flag++;
                            }
                        }
                        grade+=flag*60;
                    }
                    if(i==ROW-1 && j>0 && j<COL-1)      //last row without corner
                    {
                        for(k=-1; k<2; k++)
                        {
                            if(Map[COL*i+j+k].color!=0)
                            {
                                Map[COL*i+j+k].color=0;
                                flag++;
                            }
                            if(Map[COL*(i-1)+j+k].color!=0)
                            {
                                Map[COL*(i-1)+j+k].color=0;
                                flag++;
                            }
                        }
                        grade+=flag*60;
                    }
                    if(j==0 && i>0 && i<ROW-1)          //first column without corner
                    {
                        for(k=-1; k<2; k++)
                        {
                            if(Map[COL*(i+k)+j].color!=0)
                            {
                                Map[COL*(i+k)+j].color=0;
                                flag++;
                            }
                            if(Map[COL*(i+k)+j+1].color!=0)
                            {
                                Map[COL*(i+k)+j+1].color=0;
                                flag++;
                            }
                        }
                        grade+=flag*60;
                    }
                    if(j==COL-1 && i>0 && i<ROW-1)       //last column without corner
                    {
                        for(k=-1; k<2; k++)
                        {
                            if(Map[COL*(i+k)+j].color!=0)
                            {
                                Map[COL*(i+k)+j].color=0;
                                flag++;
                            }
                            if(Map[COL*(i+k)+j-1].color!=0)
                            {
                                Map[COL*(i+k)+j-1].color=0;
                                flag++;
                            }
                        }
                        grade+=flag*60;
                    }
                    if(i>0 && i<ROW-1 && j>0 && j<COL-1) //the rest
                    {
                        for(k=-1; k<2; k++)
                        {
                            if(Map[COL*(i-1)+j+k].color!=0)
                            {
                                Map[COL*(i-1)+j+k].color=0;
                                flag++;
                            }
                            if(Map[COL*i+j+k].color!=0)
                            {
                                Map[COL*i+j+k].color=0;
                                flag++;
                            }
                            if(Map[COL*(i+1)+j+k].color!=0)
                            {
                                Map[COL*(i+1)+j+k].color=0;
                                flag++;
                            }
                        }
                        grade+=flag*60;
                    }
                    if(step==0)
                    {
                        Map[COL*i+j].color=7;
                        while(grade!=pregrade)
                        {
                            pregrade=grade;
                            grade=grade+candyEliminate(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);
                            fall_down(Map,candytype,ROW,COL);
                        }
                    }
                    grade+=eliminateSpecialCandy(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);//process loop eliminate
                }
            }
        }
    }
    return grade;
}

int eliminateStripeAndWrap(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate)
//input a structure candy to eliminate stripe candies
//output a grade
{
    int i, j, k, grade=0, flag=0;


    if( ((Map[COL*Swap1[0]+Swap1[1]].property == 1 || Map[COL*Swap1[0]+Swap1[1]].property == 2) && Map[COL*Swap2[0]+Swap2[1]].property==3) ||
        ((Map[COL*Swap2[0]+Swap2[1]].property == 1 || Map[COL*Swap2[0]+Swap2[1]].property == 2) && Map[COL*Swap1[0]+Swap1[1]].property==3) )//inspect if a special case to be eliminated
    {
        for(i=0; i<ROW; i++)
        {
            for(j=0; j<COL; j++)
            {
                if(Swap2[0]==0)
                {
                    for(k= Swap2[0]; k< Swap2[0]+2; k++)
                    {
                        if(Map[COL*k+j].color!=0)
                        {
                            Map[COL*k+j].color=0;
                            flag++;
                        }
                    }
                }
                if(Swap2[0]==ROW-1)
                {
                    for(k= Swap2[0]-1; k< Swap2[0]+1; k++)
                    {
                        if(Map[COL*k+j].color!=0)
                        {
                            Map[COL*k+j].color=0;
                            flag++;
                        }
                    }
                }
                if(0<Swap2[0] && Swap2[0]<ROW-1)
                {
                    for(k= Swap2[0]-1; k< Swap2[0]+2; k++)
                    {
                        if(Map[COL*k+j].color!=0)
                        {
                            Map[COL*k+j].color=0;
                            flag++;
                        }
                    }
                }

                if(Swap2[1]==0)
                {
                    for(k= Swap2[1]; k< Swap2[1]+2; k++)
                    {
                        if(Map[COL*i+k].color!=0)
                        {
                            Map[COL*i+k].color=0;
                            flag++;
                        }
                    }
                }
                if(Swap2[1]==COL-1)
                {
                    for(k= Swap2[1]-1; k< Swap2[1]+1; k++)
                    {
                        if(Map[COL*i+k].color!=0)
                        {
                            Map[COL*i+k].color=0;
                            flag++;
                        }
                    }
                }
                if(0<Swap2[1] && Swap2[1]<COL-1)
                {
                    for(k= Swap2[1]-1; k< Swap2[1]+2; k++)
                    {
                        if(Map[COL*i+k].color!=0)
                        {
                            Map[COL*i+k].color=0;
                            flag++;
                        }
                    }
                }

                grade+=eliminateSpecialCandy(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);//process loop eliminate
            }
        }
    }

    grade+=flag*30;//plus grade


    return grade;
}

int eliminateWrapAndWrap(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate)
//input pointer map
//output a grade
{
    int i, j,k;
    int step,color=0;
    int grade=0, prescore=0 ;


    if(Map[COL*Swap1[0]+Swap1[1]].property == 3 && Map[COL*Swap2[0]+Swap2[1]].property==3)
    {
        for(step=0; step<2; step++)             //step 0 clear 8 and fall
        {
            //step 1 clear 9 and clear wrapped candy
            if(step==1)
            {
                color=13;
            }
            for(i=0; i<ROW; i++)
            {
                for(j=0; j<COL; j++)
                {
                    if(Map[COL*i+j].color==color )
                    {
                        if(step==1)
                        {
                            Map[COL*i+j].color=0;
                            Map[COL*i+j].property=0;        //clear to normal candy
                        }
                        if(i==0 && j==0)                    //the upper left
                        {
                            Map[COL*i+j+1].color=0;
                            Map[COL*i+j+2].color=0;
                            Map[COL*(i+1)+j].color=0;
                            Map[COL*(i+1)+j+1].color=0;
                            Map[COL*(i+1)+j+2].color=0;
                            Map[COL*(i+2)+j].color=0;
                            Map[COL*(i+2)+j+1].color=0;
                            Map[COL*(i+2)+j+2].color=0;
                            grade+=540;
                        }
                        if(i==0 && j==COL-1)                //the upper right
                        {
                            Map[COL*i+j-1].color=0;
                            Map[COL*i+j-2].color=0;
                            Map[COL*(i+1)+j].color=0;
                            Map[COL*(i+1)+j-1].color=0;
                            Map[COL*(i+1)+j-2].color=0;
                            Map[COL*(i+2)+j].color=0;
                            Map[COL*(i+2)+j-1].color=0;
                            Map[COL*(i+2)+j-2].color=0;
                            grade+=540;
                        }
                        if(i==ROW-1 && j==0)                //the lower left
                        {
                            Map[COL*i+j+1].color=0;
                            Map[COL*i+j+2].color=0;
                            Map[COL*(i-1)+j].color=0;
                            Map[COL*(i-1)+j+1].color=0;
                            Map[COL*(i-1)+j+2].color=0;
                            Map[COL*(i-2)+j].color=0;
                            Map[COL*(i-2)+j+1].color=0;
                            Map[COL*(i-2)+j+2].color=0;
                            grade+=540;
                        }
                        if(i==ROW-1 && j==COL-1)            //the lower right
                        {
                            Map[COL*i+j-1].color=0;
                            Map[COL*i+j-2].color=0;
                            Map[COL*(i-1)+j].color=0;
                            Map[COL*(i-1)+j-1].color=0;
                            Map[COL*(i-1)+j-2].color=0;
                            Map[COL*(i-2)+j].color=0;
                            Map[COL*(i-2)+j-1].color=0;
                            Map[COL*(i-2)+j-2].color=0;
                            grade+=540;
                        }
                        if(i==0 && j>0 && j<COL-1)          //first row without corner
                        {
                            for(k=-2; k<3; k++)
                            {
                                Map[COL*i+j+k].color=0;
                                Map[COL*(i+1)+j+k].color=0;
                                Map[COL*(i+2)+j+k].color=0;
                            }
                            grade+=900;
                        }
                        if(i==ROW-1 && j>0 && j<COL-1)      //last row without corner
                        {
                            for(k=-2; k<3; k++)
                            {
                                Map[COL*i+j+k].color=0;
                                Map[COL*(i-1)+j+k].color=0;
                                Map[COL*(i-2)+j+k].color=0;
                            }
                            grade+=900;
                        }
                        if(j==0 && i>0 && i<ROW-1)          //first column without corner
                        {
                            for(k=-2; k<3; k++)
                            {
                                Map[COL*(i+k)+j].color=0;
                                Map[COL*(i+k)+j+1].color=0;
                                Map[COL*(i+k)+j+2].color=0;
                            }
                            grade+=900;
                        }
                        if(j==COL-1 && i>0 && i<ROW-1)       //last column without corner
                        {
                            for(k=-1; k<2; k++)
                            {
                                Map[COL*(i+k)+j].color=0;
                                Map[COL*(i+k)+j-1].color=0;
                                Map[COL*(i+k)+j-2].color=0;
                            }
                            grade+=900;
                        }
                        if(i>0 && i<ROW-1 && j>0 && j<COL-1) //the rest
                        {
                            for(k=-2; k<3; k++)
                            {
                                Map[COL*(i-2)+j+k].color=0;
                                Map[COL*(i-1)+j+k].color=0;
                                Map[COL*i+j+k].color=0;
                                Map[COL*(i+1)+j+k].color=0;
                                Map[COL*(i+2)+j+k].color=0;
                            }
                            grade+=1500;
                        }
                        if(step==0)
                        {
                            Map[COL*i+j].color=13;
                            while(grade!=prescore)
                            {
                                prescore=grade;
                                grade+=candyEliminate(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);
                                fall_down(Map,candytype,ROW,COL);
                            }
                        }
                        grade+=eliminateSpecialCandy(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);//process loop eliminate
                    }
                }
            }
        }
    }
    return grade;
}

int eliminateChocoAndChoco(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate)
{
    int grade=0;
    int i,j;

    if(Map[COL*Swap1[0]+Swap1[1]].property == chocolate && Map[COL*Swap2[0]+Swap2[1]].property==chocolate)
    {
        grade = 50*ROW*COL;
        for(i=0; i<ROW; i++)
        {
            for(j=0; j<COL; j++)
                Map[COL*i+j].color = Map[COL*i+j].property = 0;
        }
    }
    return grade;
}

int eliminateStripeAndStrip(candy *Map, int ROW, int COL,int* Swap1,int* Swap2,int candytype, int chocolate)
{
    int grade=0;
    int i,j;

    if(Map[COL*Swap1[0]+Swap1[1]].property == 1 || Map[COL*Swap1[0]+Swap1[1]].property== 2)
    {
        if(Map[COL*Swap2[0]+Swap2[1]].property == 1 || Map[COL*Swap2[0]+Swap2[1]].property== 2)
        {
            Map[COL*Swap1[0]+Swap1[1]].property = 0;
            Map[COL*Swap2[0]+Swap2[1]].property = 0;

            for(i=0; i<ROW; i++)
            {
                for(j=0; j<COL; j++)
                {
                    if(i == Swap2[0] || j ==Swap2[1])
                    {
                        Map[COL*i+j].color=0;
                    }
                }
            }
            grade = grade + ((COL+ROW-1)*50) + eliminateSpecialCandy(Map,ROW,COL,Swap1,Swap2,candytype,chocolate);//process loop eliminate
        }
    }
    return grade;
}




