//USE MINIMUM SPANNING TREE WITH A GRAPH WITH ALL NODES CONNECTED
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("moocast.in");
ofstream fout("moocast.out");

struct cow
{
    long long x, y;
};
struct edge
{
    long long to, len;
};
long long dist(cow c1, cow c2)
{
    return ((c1.x - c2.x) * (c1.x - c2.x)) + ((c1.y - c2.y) * (c1.y - c2.y));
}
struct cpr
{
    bool operator()(edge const& c1, edge const& c2)
    {
        return c1.len > c2.len;
    }
};

cow cows[1000];
bool visited[1000];
vector<int> vis;
priority_queue<edge, vector<edge>, cpr> order;
int main()
{
    int n;
    long long biggest = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> cows[i].x >> cows[i].y;
    vis.push_back(0); visited[0] = true;
    for(int i = 1; i < n; i ++)
        order.push({i, dist(cows[0], cows[i])});
    while(vis.size() < n)
    {
        if(visited[order.top().to])
        {
            order.pop(); continue;
        }
        vis.push_back(order.top().to);
        visited[order.top().to] = true;
        biggest = max(biggest, order.top().len);
        int saved = order.top().to;
        order.pop();
        for(int i = 0; i < n; i ++)
            if(!visited[i])
                order.push({i, dist(cows[saved], cows[i])});
    }
    fout << biggest << endl;
}
