#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int l[1010];
int r[1010];
char s[510];
vector<int> e;
int visited[1010];
int main()
{
    int n, m, k, cur = 1, idx = 0;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i ++)
        cin >> l[i] >> r[i];
    for(int i = 0; i < m; i ++)
        cin >> s[i];
    for(int i = 0; i <= n; i ++) visited[i] = -1;
    while(visited[cur] == -1)
    {
        visited[cur] = idx; idx ++;
        e.push_back(cur);
        for(int i = 0; i < m; i ++)
        {
            if(s[i] == 'L')
                cur = l[cur - 1];
            else
                cur = r[cur - 1];
        }
        if(idx == k) { cout << cur << "\n"; return 0; }
    }
    e.push_back(cur);
    k -= visited[cur];
    k = k % (idx - visited[cur]);
    cout << e[visited[cur] + k] << "\n";
}
