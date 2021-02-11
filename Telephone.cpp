#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

struct st
{
    int from, to, d;
    const bool operator>(const st& other) const
    {
        return d > other.d;
    }
};

int nums[50010];
vector<int> can[60];
priority_queue<st, vector<st>, greater<st>> nextInLine;
int len[60][50010];
vector<int> group[60];
int main()
{
    int n, k, curF, curT, curD, ans = 2000000000;
    cin >> n >> k;
    string c;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        nums[i] --;
        group[nums[i]].push_back(i);
    }
    for(int i = 0; i < k; i ++)
    {
        cin >> c;
        for(int j = 0; j < c.length(); j ++)
            if(c[j] == '1')
                can[i].push_back(j);
    }
    for(int i = 0; i < k; i ++)
        for(int j = 0; j < n; j ++)
            len[i][j] = 2000000000;
    for(int i = 0; i < can[nums[0]].size(); i ++)
        for(int j = 0; j < group[can[nums[0]][i]].size(); j ++)
        {
            if(group[can[nums[0]][i]][j] == n - 1)
            {
                cout << n - 1 << "\n";
                return 0;
            }
            nextInLine.push({0, group[can[nums[0]][i]][j], group[can[nums[0]][i]][j]});
            len[nums[0]][group[can[nums[0]][i]][j]] = group[can[nums[0]][i]][j];
        }
    while(!nextInLine.empty())
    {
        curF = nextInLine.top().from;
        curT = nextInLine.top().to;
        curD = nextInLine.top().d;
        nextInLine.pop();
        if(curD > len[nums[curF]][curT]) continue;
        for(int i = 0; i < can[nums[curT]].size(); i ++)
            for(int j = 0; j < group[can[nums[curT]][i]].size(); j ++)
                if(len[nums[curT]][group[can[nums[curT]][i]][j]] > curD + abs(group[can[nums[curT]][i]][j] - curT))
                {
                    nextInLine.push({curT, group[can[nums[curT]][i]][j], curD + abs(group[can[nums[curT]][i]][j] - curT)});
                    len[nums[curT]][group[can[nums[curT]][i]][j]] = curD + abs(group[can[nums[curT]][i]][j] - curT);
                }
    }
    for(int i = 0; i < k; i ++)
        ans = min(ans, len[i][n - 1]);
    cout << ((ans==2000000000)?-1:ans) << "\n";
}
