#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <bitset>
using namespace std;
typedef pair<int, int> pii;

int n, m;
int board[510][510];
vector<pii> nums;
queue<pii> nextInLine;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
bitset<250010> visited;
int bs(int l, int r)
{
    int mid = (l + r) / 2;
    if(l != r)
    {
        int curR, curC;
        visited.reset();
        nextInLine.push(pii(nums[0].first, nums[0].second));
        while(!nextInLine.empty())
        {
            curR = nextInLine.front().first;
            curC = nextInLine.front().second;
            nextInLine.pop();
            if(visited[curR * m + curC]) continue;
            for(int i = 0; i < 4; i ++)
            {
                if(curR + dr[i] < 0 || curR + dr[i] >= n || curC + dc[i] < 0 || curC + dc[i] >= m) continue;
                if(abs(board[curR][curC] - board[curR + dr[i]][curC + dc[i]]) > mid) continue;
                nextInLine.push(pii(curR + dr[i], curC + dc[i]));
            }
            visited[curR * m + curC] = true;
        }
        bool good = true;
        for(int i = 0; i < nums.size(); i ++)
            if(!visited[nums[i].first * m + nums[i].second])
            {
                good = false;
                break;
            }
        if(r == l + 1)
        {
            if(good) return l;
            return r;
        }
        if(good) return bs(l, mid);
        return bs(mid, r);
    }
    return mid;
}
int main()
{
    int cur;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> board[i][j];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            cin >> cur;
            if(cur == 1)
                nums.push_back(pii(i, j));
        }
    cout << bs(0, 2000000000) << "\n";
}
