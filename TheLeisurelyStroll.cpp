#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p, n1, n2, n3, maxN = 0;
int turns[1000][2];
vector<int> path;
void dfs(int cur)
{
    path.push_back(cur);
    maxN = max(maxN, (int)path.size());
    if(turns[cur][0] != 0) dfs(turns[cur][0]);
    if(turns[cur][1] != 0) dfs(turns[cur][1]);
    path.pop_back();
}

int main()
{
    cin >> p;
    for(int i = 0; i < p; i ++)
    {
        cin >> n1 >> n2 >> n3;
        turns[n1][0] = n2;
        turns[n1][1] = n3;
    }
    dfs(1);
    cout << maxN << endl;
}
