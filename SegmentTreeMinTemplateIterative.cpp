int n;
int tree[400010];
int nums[200010];
void makeTree(int nums[])
{
    for(int i = 0; i < n; i ++)
        tree[n + i] = nums[i];
    for(int i = n - 1; i > 0; -- i)
        tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
}
void update(int idx, int val)
{
    tree[idx + n] = val;
    idx += n;
    for(int i = idx; i > 1; i >>= 1)
        tree[i >> 1] = min(tree[i], tree[i ^ 1]);
}
int minQ(int l, int r) // inclusive l, exclusive r
{
    int ans = 2000000000;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if(l & 1)
            ans = min(ans, tree[l ++]);
        if(r & 1)
            ans = min(ans, tree[-- r]);
    }
    return ans;
}
