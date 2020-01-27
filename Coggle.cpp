#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<string> dic;
set<string> sub;
set<string> used;
char mat[5][5];
bool visited[5][5];
int ans = 0;
void dfs(int r, int c, string s)
{
    if(r < 0 || r > 4 || c < 0 || c > 4) return;
    if(visited[r][c]) return;
    if(sub.find(s) == sub.end()) return;
    visited[r][c] = true;
    s += mat[r][c];
    if(dic.find(s) != dic.end() && used.find(s) == used.end()) 
    {
        used.insert(s);
        ans ++;
    }
    if(s.length() >= 20)
        return;
    for(int i = -1; i <= 1; i ++)
        for(int j = -1; j <= 1; j ++)
        {
            if(i == j && i == 0) continue;
            dfs(r + i, c + j, s);
        }
    visited[r][c] = false;
}
int main()
{
    string s;
    for(int i = 0; i < 5; i ++)
        for(int j = 0; j < 5; j ++)
            cin >> mat[i][j];
    while(cin >> s)
    {
        dic.insert(s);
        for(int i = 0; i <= s.length(); i ++)
            sub.insert(s.substr(0, i));
    }
    for(int i = 0; i < 5; i ++)
        for(int j = 0; j < 5; j ++)
        {
            for(int k = 0; k < 5; k ++)
                for(int l = 0; l < 5; l ++)
                    visited[k][l] = false;
            dfs(i, j, "");
        }
    cout << ans << endl;
}
