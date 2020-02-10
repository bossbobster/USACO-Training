#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p, ns, t, n1, n2, n3;
bool done = false;
int turns[5000][2];
vector<int> path;
void dfs(int cur)
{
    if(done) return;
    path.push_back(cur);
    if(cur == t)
    {
        done = true;
        cout << path.size() << "\n";
        for(int i = 0; i < path.size(); i ++)
            cout << path[i] << "\n";
        return;
    }
    if(turns[cur][0] == 0) { path.pop_back(); return; }
    dfs(turns[cur][0]);
    if(done) return;
    dfs(turns[cur][1]);
    path.pop_back();
}

int main()
{
    cin >> p >> ns >> t;
    for(int i = 0; i < ns; i ++)
    {
        cin >> n1 >> n2 >> n3;
        turns[n1][0] = n2;
        turns[n1][1] = n3;
    }
    dfs(1);
}
