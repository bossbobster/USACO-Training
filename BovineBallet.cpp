#include <iostream>
#include <algorithm>
using namespace std;

int feet[4][2];
int idx = 0;
char dir = 'n';
int hsh(char c1, char c2)
{
    if(c1 == 'F' && c2 == 'L') return 0;
    if(c1 == 'F' && c2 == 'R') return 1;
    if(c1 == 'R' && c2 == 'L') return 2;
    return 3;
}
void move(char c)
{
    if(dir == 'n')
    {
        if(c == 'F') feet[idx][0] --;
        else if(c == 'B') feet[idx][0] ++;
        else if(c == 'R') feet[idx][1] ++;
        else feet[idx][1] --;
    }
    else if(dir == 's')
    {
        if(c == 'F') feet[idx][0] ++;
        else if(c == 'B') feet[idx][0] --;
        else if(c == 'R') feet[idx][1] --;
        else feet[idx][1] ++;
    }
    else if(dir == 'e')
    {
        if(c == 'F') feet[idx][1] ++;
        else if(c == 'B') feet[idx][1] --;
        else if(c == 'R') feet[idx][0] ++;
        else feet[idx][0] --;
    }
    else
    {
        if(c == 'F') feet[idx][1] --;
        else if(c == 'B') feet[idx][1] ++;
        else if(c == 'R') feet[idx][0] --;
        else feet[idx][0] ++;
    }
}
void pivot()
{
    for(int i = 0; i < 4; i ++)
    {
        if(i == idx) continue;
        feet[i][0] -= feet[idx][0];
        feet[i][1] -= feet[idx][1];
        int tmp = feet[i][0];
        feet[i][0] = feet[i][1];
        feet[i][1] = -tmp;
    }
    for(int i = 0; i < 4; i ++)
    {
        if(i == idx) continue;
        feet[i][0] += feet[idx][0];
        feet[i][1] += feet[idx][1];
    }
    if(dir == 'n') dir = 'e';
    else if(dir == 'e') dir = 's';
    else if(dir == 's') dir = 'w';
    else dir = 'n';
}
int main()
{
    int n, minL = 0, maxR = 1, minU = 0, maxD = 1;
    string cur;
    cin >> n;
    feet[0][0] = 0; feet[0][1] = 0;
    feet[1][0] = 0; feet[1][1] = 1;
    feet[2][0] = 1; feet[2][1] = 0;
    feet[3][0] = 1; feet[3][1] = 1;
    for(int i = 0; i < n; i ++)
    {
        cin >> cur;
        idx = hsh(cur[0], cur[1]);
        if(cur[2] == 'P') pivot();
        else move(cur[2]);
        minL = min(minL, min(min(feet[0][1], feet[1][1]), min(feet[2][1], feet[3][1])));
        maxR = max(maxR, max(max(feet[0][1], feet[1][1]), max(feet[2][1], feet[3][1])));
        minU = min(minU, min(min(feet[0][0], feet[1][0]), min(feet[2][0], feet[3][0])));
        maxD = max(maxD, max(max(feet[0][0], feet[1][0]), max(feet[2][0], feet[3][0])));
    }
    cout << (maxD - minU + 1) * (maxR - minL + 1) << endl;
}
