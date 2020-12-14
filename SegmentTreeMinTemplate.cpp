#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

// updates value at upIdx to val.
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
// get the min from lq to rq in the array
int minQ(int nums[], int* tree, int l, int r, int lq, int rq, int curIdx)
{
    if(lq == rq)
        return nums[lq];
    if(r < lq || l > rq)
        return INFINITY;
    if(lq <= l && rq >= r)
        return tree[curIdx];
    int mid = (l + r) / 2;
    return min(minQ(nums, tree, l, mid, lq, rq, curIdx * 2 + 1), minQ(nums, tree, mid + 1, r, lq, rq, curIdx * 2 + 2));
}
// recursive function useful for making segment tree
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
// main function to make segment tree
int* makeTree(int nums[], int n)
{
    int size = 2 * (int)pow(2, (int)ceil(log2(n))) + 5;
    int* tree = new int[size];
    makeTreeRec(nums, tree, 0, n - 1, 0);
    return tree;
}
