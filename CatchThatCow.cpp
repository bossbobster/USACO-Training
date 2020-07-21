#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue<pair<long long, int>> nextInLine;
bool visited[1000000];
int main()
{
    long long n, k, cur, d;
    cin >> n >> k;
    nextInLine.push(pair<long long, int>(n, 0));
    while(!nextInLine.empty())
    {
        cur = nextInLine.front().first;
        d = nextInLine.front().second;
        nextInLine.pop();
        if(cur < 0 || cur > 100000) continue;
        if(visited[cur]) continue;
        visited[cur] = true;
        if(cur == k) break;
        nextInLine.push(pair<long long, int>(cur - 1, d + 1));
        nextInLine.push(pair<long long, int>(cur + 1, d + 1));
        nextInLine.push(pair<long long, int>(cur * 2, d + 1));
    }
    cout << d << "\n";
}
