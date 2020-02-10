#include <iostream>
using namespace std;

int n, maxL = 0;
string maze[5];
bool visited[5][5];
bool good = false;

void findLong(int r, int c, string cur)
{
    if(r < 0 || r >= n || c < 0 || c >= n) return;
    if(visited[r][c]) return;
    visited[r][c] = true;
    cur += maze[r][c];
    good = true;
    for(int i = 1; i <= 12; i ++)
    {
        if(cur.length() % 2 == 1) { good = false; break; }
        if(cur.length() < i * 2) break;
        if(cur.length() != i * 2) continue;
        for(int j = 0; j < i; j ++)
            if(cur[j] != '(') { good = false; break; }
        for(int j = i; j < i * 2; j ++)
            if(cur[j] != ')') { good = false; break; }
    }
    if(good) maxL = max(maxL, (int)cur.length());
    findLong(r + 1, c, cur);
    findLong(r - 1, c, cur);
    findLong(r, c + 1, cur);
    findLong(r, c - 1, cur);
    visited[r][c] = false;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> maze[i];
    findLong(0, 0, "");
    cout << maxL << endl;
}
