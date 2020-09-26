#include <iostream>
#include <algorithm>
using namespace std;

struct edge
{
    int s, e, c;
};

edge edges[1000];
int dist[1000];
int main()
{
    int d, p, c, f, s, one, two, three, ans = 0;
    cin >> d >> p >> c >> f >> s;
    for(int i = 0; i <= c; i ++) dist[i] = 2000000000;
    dist[s] = 0;
    for(int i = 0; i < p; i ++)
    {
        cin >> one >> two;
        edges[i].s = one; edges[i].e = two; edges[i].c = -(d);
    }
    for(int i = 0; i < f; i ++)
    {
        cin >> one >> two >> three;
        edges[i + p].s = one; edges[i + p].e = two; edges[i + p].c = -(d) + three;
    }
    for(int i = 0; i < c; i ++)
        for(int j = 0; j < p + f; j ++)
        {
            if(dist[edges[j].s] + edges[j].c < dist[edges[j].e])
            {
                if(i == c - 1) { ans = -1; break; }
                dist[edges[j].e] = dist[edges[j].s] + edges[j].c;
                ans = min(ans, dist[edges[j].e]);
            }
        }
    if(ans == -1) { cout << ans << "\n"; return 0; }
    ans *= -1; ans += d;
    cout << ans << "\n";
}
