#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;

struct thing
{
    int t, idx;
    bool operator<(const thing& other) const
    {
        return t > other.t;
    }
};

struct racer
{
    int l, m;
    vector<int> a;
};

bitset<1010> visited;
priority_queue<thing> nextInLine;
racer racers[1010];
int main()
{
    int n, tmp, cur, tm, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> racers[i].l >> racers[i].m;
        for(int j = 0; j < racers[i].m; j ++)
        {
            cin >> tmp;
            racers[i].a.push_back(tmp);
        }
    }
    thing temp;
    temp.idx = 0;
    temp.t = racers[0].l;
    nextInLine.push(temp);
    visited[0] = true;
    do
    {
        cur = nextInLine.top().idx;
        tm = nextInLine.top().t;
        for(int i = 0; i < racers[cur].m; i ++)
            if(!visited[racers[cur].a[i] - 1])
            {
                thing temp;
                temp.t = tm + racers[racers[cur].a[i] - 1].l;
                temp.idx = racers[cur].a[i] - 1;
                nextInLine.push(temp);
                visited[racers[cur].a[i] - 1] = true;
            }
        ans = max(ans, nextInLine.top().t);
        nextInLine.pop();
    } while(!nextInLine.empty());
    cout << ans;
}
