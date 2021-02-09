#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ifstream fin("promote.in");
ofstream fout("promote.out");

pii endpts[100010];
pii nums[100010];
vector<int> adj[100010];
int bit[100010];
int ans[100010];
int sum(int arr[], int idx)
{
    int ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans += arr[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void update(int arr[], int idx, int val, int size)
{
    idx ++;
    while(idx <= size)
    {
        arr[idx] += val;
        idx += idx & (-idx);
    }
}

int cnt = 0;
void euler(int cur, int par)
{
    endpts[cur].first = cnt ++;
    for(int i = 0; i < adj[cur].size(); i ++)
        if(adj[cur][i] != par)
            euler(adj[cur][i], cur);
    endpts[cur].second = cnt - 1;
}

bool comp(pii p1, pii p2)
{
    if(p1.f == p2.f) return p1.s < p2.s;
    return p1.f > p2.f;
}
int main()
{
    int n, tmp;
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> nums[i].f;
        nums[i].s = i;
    }
    sort(nums, nums + n, comp);
    for(int i = 0; i < n - 1; i ++)
    {
        fin >> tmp;
        adj[tmp - 1].push_back(i + 1);
    }
    euler(0, -1);
    for(int i = 0; i < n; i ++)
    {
        ans[nums[i].s] = sum(bit, endpts[nums[i].s].s) - sum(bit, endpts[nums[i].s].f);
        update(bit, endpts[nums[i].s].f, 1, n);
    }
    for(int i = 0; i < n; i ++)
        fout << ans[i] << "\n";
}
