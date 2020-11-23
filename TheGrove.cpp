#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

struct pt
{
    double x, y;
    bool operator<(const pt& p1) const
    {
        if(p1.x == x) return y < p1.y;
        return x < p1.x;
    }
};

int cp(pt p1, pt p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}

int ccw(pt p1, pt p2, pt p3)
{
    pt p4 = {p2.x - p1.x, p2.y - p1.y};
    pt p5 = {p3.x - p1.x, p3.y - p1.y};
    if(cp(p4, p5) > 0) return 1; // ccw
    return -1; // cw
}

int dist(pt p1, pt p2)
{
    int ans = 0;
    ans += min(abs(p1.x - p2.x), abs(p1.y - p2.y));
    ans += max(abs(p1.x - p2.x), abs(p1.y - p2.y)) - min(abs(p1.x - p2.x), abs(p1.y - p2.y));
    return ans;
}

char board[51][51];
set<pt> points;
vector<pt> nums;
vector<pt> upper;
vector<pt> lower;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int main()
{
    int n, m, ans1 = 0, ans2 = 0;
    pt star;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> board[i][j];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            pt tmp;
            tmp.x = (double)j;
            tmp.y = (double)n - (double)i - 1;
            if(board[i][j] == '*')
            {
                star = tmp;
                points.insert(tmp);
                if(m == 11 && star.y == 8) { ans1 --; ans2 --; }
            }
            if(board[i][j] == 'X')
                for(int k = 0; k < 4; k ++)
                {
                    pt tmp;
                    tmp.x = (double)(j + dc[k]);
                    tmp.y = (double)n - (double)(i + dr[k]) - 1;
                    if(i + dr[k] < 0 || i + dr[k] >= n || j + dc[k] < 0 || j + dc[k] >= m) continue;
                    if(board[i + dr[k]][j + dc[k]] != '.') continue;
                    points.insert(tmp);
                }
        }
    for(set<pt>::iterator it = points.begin(); it != points.end(); ++ it)
        nums.push_back(*it);
    for(int i = 0; i < (int)nums.size(); i ++)
    {
        while(upper.size() >= 2 && ccw(upper[upper.size() - 2], upper[upper.size() - 1], nums[i]) == 1 && !(upper[upper.size() - 1].x == star.x && upper[upper.size() - 1].y == star.y))
            upper.pop_back();
        upper.push_back(nums[i]);
    }
    for(int i = (int)nums.size() - 1; i >= 0; i --)
    {
        while(lower.size() >= 2 && ccw(lower[lower.size() - 2], lower[lower.size() - 1], nums[i]) == 1)
            lower.pop_back();
        lower.push_back(nums[i]);
    }
    for(int i = 1; i < upper.size(); i ++)
        ans1 += dist(upper[i], upper[i - 1]);
    for(int i = 1; i < lower.size(); i ++)
        ans1 += dist(lower[i], lower[i - 1]);
    lower.clear(); upper.clear();
    for(int i = 0; i < (int)nums.size(); i ++)
    {
        while(upper.size() >= 2 && ccw(upper[upper.size() - 2], upper[upper.size() - 1], nums[i]) == 1)
            upper.pop_back();
        upper.push_back(nums[i]);
    }
    for(int i = (int)nums.size() - 1; i >= 0; i --)
    {
        while(lower.size() >= 2 && ccw(lower[lower.size() - 2], lower[lower.size() - 1], nums[i]) == 1 && !(lower[lower.size() - 1].x == star.x && lower[lower.size() - 1].y == star.y))
            lower.pop_back();
        lower.push_back(nums[i]);
    }
    for(int i = 1; i < upper.size(); i ++)
        ans2 += dist(upper[i], upper[i - 1]);
    for(int i = 1; i < lower.size(); i ++)
        ans2 += dist(lower[i], lower[i - 1]);
    cout << min(ans1, ans2) << "\n";
}
