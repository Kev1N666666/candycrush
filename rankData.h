#pragma once

typedef struct rankData
{
    int score;
    char name[15];
    char sdate[9];
    char stime[9];
    char data[256];

} rankData;

void DataRankOutput(int score, int turn);

