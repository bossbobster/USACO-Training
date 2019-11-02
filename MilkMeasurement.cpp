#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("measurement.in");
ofstream fout("measurement.out");

struct cow
{
    int day, c;
    string s;
};

bool cpr(cow c1, cow c2)
{
    return c1.day < c2.day;
}

cow cows[110];
int vals[3] = {7, 7, 7};
int main()
{
    int n, total = 0;
    string tmpC, board = "", prevBoard = "";
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> cows[i].day;
        fin >> tmpC;
        if(tmpC == "Bessie") cows[i].c = 0;
        else if(tmpC == "Elsie") cows[i].c = 1;
        else cows[i].c = 2;
        fin >> cows[i].s;
    }
    sort(cows, cows + n, cpr);
    for(int i = 0; i < n; i ++)
    {
        board = "";
        if(cows[i].s[0] == '+')
            vals[cows[i].c] += stoi(cows[i].s.substr(1, cows[i].s.length() - 1));
        else
            vals[cows[i].c] -= stoi(cows[i].s.substr(1, cows[i].s.length() - 1));
        board = "0";
        for(int j = 1; j < 3; j ++)
        {
            if(vals[j] > vals[board[0] - '0'])
            {
                board = "";
                board += j + '0';
            }
            if(vals[j] == vals[board[0] - '0']) board += j + '0';
        }
        if(board != prevBoard) total ++;
        prevBoard = board;
    }
    fout << total << endl;
}
