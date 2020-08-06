#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, double> piii;

int dist(int x1, int y1, int x2, int y2)
{
    return ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
}
int n, x, y, rat, initial;
bool done = false;
piii r[1100];
bool visited[1100];
void rec(int cur, double curD)
{
    if(done) return;
    if(r[cur].first.first == x && r[cur].first.second == y)
    {
        cout << (int)curD << "\n";
        done = true;
        return;
    }
    for(int i = 0; i < n; i ++)
        if(!visited[i] && dist(r[cur].first.first, r[cur].first.second, r[i].first.first, r[i].first.second) == (r[cur].second + r[i].second) * (r[cur].second + r[i].second))
        {
            visited[i] = true;
            rec(i, curD + (10000.0 * (double)r[initial].second / (double)r[i].second));
        }
}
int main()
{
    cin >> n >> x >> y;
    for(int i = 0; i < n; i ++)
    {
        cin >> r[i].first.first >> r[i].first.second >> r[i].second;
        if(r[i].first.first == 0 && r[i].first.second == 0)
            initial = i;
    }
    visited[initial] = true;
    rec(initial, 10000.0);
}
