#include <iostream>
#include <algorithm>
#include <math.h>
#include <deque>
#include <vector>
#include <unordered_map>
using namespace std;

struct pt
{
    int x, y, idx;
};
struct ln
{
    int idx, h, dist;
};

bool compx(pt p1, pt p2)
{
    return p1.x < p2.x;
}
bool compy(pt p1, pt p2)
{
    return p1.y < p2.y;
}

pt nums[100010];
unordered_map<int, vector<pt>> xs;
unordered_map<int, vector<pt>> ys;
int up[100010];
int down[100010];
int lef[100010];
int righ[100010];
bool visited[100010][2];
deque<ln> nextInLine;
int main()
{
    int n, curN, curDir, curD, t = 0;
    pt l, b;
    cin >> n >> l.x >> l.y >> b.x >> b.y;
    l.idx = 0; b.idx = n + 1;
    nums[0] = l;
    for(int i = 1; i <= n; i ++)
    {
        cin >> nums[i].x >> nums[i].y;
        nums[i].idx = i;
        xs[nums[i].x].push_back(nums[i]);
        ys[nums[i].y].push_back(nums[i]);
        up[i] = down[i] = lef[i] = righ[i] = -1;
    }
    up[0] = down[0] = lef[0] = righ[0] = up[n + 1] = down[n + 1] = lef[n + 1] = righ[n + 1] = -1;
    nums[n + 1] = b;
    xs[nums[0].x].push_back(nums[0]); ys[nums[0].y].push_back(nums[0]);
    xs[nums[n + 1].x].push_back(nums[n + 1]); ys[nums[n + 1].y].push_back(nums[n + 1]);
    for(unordered_map<int, vector<pt>>::iterator it = xs.begin(); it != xs.end(); ++ it)
    {
        sort(it->second.begin(), it->second.end(), compy);
        for(int i = 0; i < it->second.size(); i ++)
        {
            if(i != 0) down[it->second[i].idx] = it->second[i - 1].idx;
            if(i != it->second.size() - 1) up[it->second[i].idx] = it->second[i + 1].idx;
        }
    }
    for(unordered_map<int, vector<pt>>::iterator it = ys.begin(); it != ys.end(); ++ it)
    {
        sort(it->second.begin(), it->second.end(), compx);
        for(int i = 0; i < it->second.size(); i ++)
        {
            if(i != 0) lef[it->second[i].idx] = it->second[i - 1].idx;
            if(i != it->second.size() - 1) righ[it->second[i].idx] = it->second[i + 1].idx;
        }
    }
    nextInLine.push_back({0, 0, 0});
    nextInLine.push_back({0, 1, 0});
    while(!nextInLine.empty() && t < 500000)
    {
        curN = nextInLine.front().idx;
        curDir = nextInLine.front().h;
        curD = nextInLine.front().dist;
        t ++;
        nextInLine.pop_front();
        if(visited[curN][curDir]) continue;
        if(curN == n + 1)
        {
            cout << curD << "\n";
            return 0;
        }
        if(curDir == 1)
        {
            if(lef[curN] != -1)
            {
                if(!visited[lef[curN]][curDir])
                    nextInLine.push_front({lef[curN], curDir, curD});
                if(!visited[lef[curN]][(curDir + 1) % 2])
                    nextInLine.push_back({lef[curN], (curDir + 1) % 2, curD + 1});
            }
            if(righ[curN] != -1)
            {
                if(!visited[righ[curN]][curDir])
                    nextInLine.push_front({righ[curN], curDir, curD});
                if(!visited[righ[curN]][(curDir + 1) % 2])
                    nextInLine.push_back({righ[curN], (curDir + 1) % 2, curD + 1});
            }
        }
        else
        {
            if(up[curN] != -1)
            {
                if(!visited[up[curN]][curDir])
                    nextInLine.push_front({up[curN], curDir, curD});
                if(!visited[up[curN]][(curDir + 1) % 2])
                    nextInLine.push_back({up[curN], (curDir + 1) % 2, curD + 1});
            }
            if(down[curN] != -1)
            {
                if(!visited[down[curN]][curDir])
                    nextInLine.push_front({down[curN], curDir, curD});
                if(!visited[down[curN]][(curDir + 1) % 2])
                    nextInLine.push_back({down[curN], (curDir + 1) % 2, curD + 1});
            }
        }
        visited[curN][curDir] = true;
    }
    cout << -1 << "\n";
}
