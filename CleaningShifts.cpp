#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> pii;

void update(int nums[], int* tree, int l, int r, int curIdx, int upIdx, int val)
{
    if(l == r)
    {
        tree[curIdx] = val;
        nums[upIdx] = val;
        return;
    }
    int mid = (l + r) / 2;
    if(upIdx >= l && upIdx <= mid)
        update(nums, tree, l, mid, curIdx * 2 + 1, upIdx, val);
    else
        update(nums, tree, mid + 1, r, curIdx * 2 + 2, upIdx, val);
    tree[curIdx] = min(tree[curIdx * 2 + 1], tree[curIdx * 2 + 2]);
}
int minQ(int nums[], int* tree, int l, int r, int lq, int rq, int curIdx)
{
    if(lq == rq)
        return nums[lq];
    if(r < lq || l > rq)
        return 2000000000;
    if(lq <= l && rq >= r)
        return tree[curIdx];
    int mid = (l + r) / 2;
    return min(minQ(nums, tree, l, mid, lq, rq, curIdx * 2 + 1), minQ(nums, tree, mid + 1, r, lq, rq, curIdx * 2 + 2));
}
int makeTreeRec(int nums[], int* tree, int l, int r, int curIdx)
{
    if(l == r)
    {
        tree[curIdx] = nums[l];
        return tree[curIdx];
    }
    int mid = (l + r) / 2;
    tree[curIdx] = min(makeTreeRec(nums, tree, l, mid, curIdx * 2 + 1), makeTreeRec(nums, tree, mid + 1, r, curIdx * 2 + 2));
    return tree[curIdx];
}
int* makeTree(int nums[], int n)
{
    int size = 2 * (int)pow(2, (int)ceil(log2(n))) + 5;
    int* tree = new int[size];
    makeTreeRec(nums, tree, 0, n - 1, 0);
    return tree;
}

vector<pii> endsIn[86500];
int dp[86500];
int main()
{
    int n, m, e, one, two, three, minN, curAns;
    cin >> n >> m >> e;
    for(int i = 0; i < n; i ++)
    {
        cin >> one >> two >> three;
        endsIn[two].push_back(pii(one, three));
    }
    for(int i = m; i <= 86500; i ++)
        dp[i] = 2000000000;
    int* seg = makeTree(dp, 86490);
    for(int i = m; i <= 86400; i ++)
    {
        curAns = 2000000000;
        for(int j = 0; j < endsIn[i].size(); j ++)
        {
            if(endsIn[i][j].first == 0)
                curAns = min(curAns, endsIn[i][j].second);
            else
            {
                minN = minQ(dp, seg, 0, 86489, endsIn[i][j].first - 1, i - 1, 0);
                if(minN != 2000000000)
                    curAns = min(curAns, endsIn[i][j].second + minN);
            }
        }
        update(dp, seg, 0, 86489, 0, i, curAns);
    }
    int ans = minQ(dp, seg, 0, 86489, e, 86400, 0);
    cout << ((ans == 2000000000)?-1:ans) << "\n";
}
