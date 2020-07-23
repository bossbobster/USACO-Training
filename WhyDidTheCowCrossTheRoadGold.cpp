#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> piiii;
typedef pair<int, int> pii;

ifstream fin("visitfj.in");
ofstream fout("visitfj.out");

struct state
{
    int cur, r, c, d;
    bool operator<(const state& s2)
    {
        return cur < s2.cur;
    }
    bool operator>(const state& s2)
    {
        return cur > s2.cur;
    }
};

int grass[110][110];
int len[110][110][3];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
priority_queue<piiii, vector<piiii>, greater<piiii>> nextInLine;
int main()
{
    int n, t, curVal, curR, curC, curD;
    fin >> n >> t;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            fin >> grass[i][j];
            len[i][j][0] = len[i][j][1] = len[i][j][2] = 2000000000;
        }
    nextInLine.push(piiii(pii(0, 0), pii(0, 0)));
    len[0][0][0] = 0;
    while(!nextInLine.empty())
    {
        curVal = nextInLine.top().first.first;
        curR = nextInLine.top().first.second;
        curC = nextInLine.top().second.first;
        curD = nextInLine.top().second.second;
        nextInLine.pop();
        if(curR < 0 || curR >= n || curC < 0 || curC >= n) continue;
        if(curD % 3 == 0 && curD != 0)
            len[curR][curC][0] += grass[curR][curC];
        for(int i = 0; i < 4; i ++)
        {
            if(curR + dr[i] >= 0 && curR + dr[i] < n && curC + dc[i] >= 0 && curC + dc[i] < n)
                if(len[curR + dr[i]][curC + dc[i]][(curD + 1) % 3] > len[curR][curC][curD % 3] + t)
                {
                    len[curR + dr[i]][curC + dc[i]][(curD + 1) % 3] = len[curR][curC][curD % 3] + t;
                    nextInLine.push(piiii(pii(len[curR + dr[i]][curC + dc[i]][(curD + 1) % 3], curR + dr[i]), pii(curC + dc[i], curD + 1)));
                }
        }
    }
    fout << min(len[n - 1][n - 1][0], min(len[n - 1][n - 1][1], len[n - 1][n - 1][2])) << "\n";
}
