#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <set>
#include <vector>
using namespace std;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;

int adj[100][100];
int cnt[100];
set<int> nodes;
bool moved = true;
int main()
{
    int n, d, l, r;
    char a, b;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> a >> b >> d;
        if(adj[a - 'A'][b - 'A'] == 0) { cnt[a - 'A'] ++; cnt[b - 'A'] ++; }
        adj[a - 'A'][b - 'A'] += d; adj[b - 'A'][a - 'A'] += d;
        nodes.insert(a - 'A'); nodes.insert(b - 'A');
    }
    nodes.erase(0); nodes.erase(25);
    while(moved)
    {
        moved = false;
        for(auto i : nodes)
        {
            if(cnt[i] == 2)
            {
                moved = true;
                l = r = 99;
                for(int j = 0; j < 60; j ++)
                    if(adj[i][j] != 0)
                    {
                        if(l == 99) l = j;
                        else r = j;
                    }
                if(adj[l][r] != 0) { cnt[l] --; cnt[r] --; }
                adj[l][r] += min(adj[l][i], adj[r][i]);
                adj[r][l] += min(adj[l][i], adj[r][i]);
                adj[l][i] = adj[i][l] = adj[r][i] = adj[i][r] = 0;
                cnt[i] = 0;
            }
            if(cnt[i] == 1)
            {
                moved = true;
                for(int j = 0; j < 60; j ++)
                    if(adj[i][j] != 0)
                    {
                        adj[i][j] = adj[j][i] = 0;
                        cnt[j] --;
                        break;
                    }
                cnt[i] = 0;
            }
        }
    }
    for(int i = 0; i < 60; i ++)
    {
        if(moved) break;
        for(int j = 0; j < 60; j ++)
            if(adj[i][j] != 0)
            {
                cout << adj[i][j] << "\n";
                moved = true;
                break;
            }
    }
}
