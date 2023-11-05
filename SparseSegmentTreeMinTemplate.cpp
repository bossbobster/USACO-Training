#include <algorithm>
using namespace std;
typedef long long ll;

const double inf = 1e9;
struct node
{
    node* left = nullptr;
    node* right = nullptr;
    ll val;
    node(node* left, node* right)
    {
        this->left = left; this->right = right; this->val = -inf;
    }
};
node* update(node* cur, int l, int r, int upIdx, ll val)
{
    if(cur == nullptr) cur = new node(nullptr, nullptr);
    int mid = (l + r) / 2;
    if(l == upIdx && l == r)
    {
        cur->val = max(cur->val, val);
        return cur;
    }
    if(upIdx >= l && upIdx <= mid)
        cur->left = update(cur->left, l, mid, upIdx, val);
    else
        cur->right = update(cur->right, mid+1, r, upIdx, val);
    ll num = -inf;
    if(cur->left != nullptr) num = max(num, cur->left->val);
    if(cur->right != nullptr) num = max(num, cur->right->val);
    cur->val = num;
    return cur;
}
ll mx(node* cur, int l, int r, int lq, int rq)
{
    int mid = (l + r) / 2;
    if(l > rq || r < lq || l > r) return -inf;
    if(l >= lq && r <= rq)
        return cur->val;
    ll num = -inf;
    if(cur->left != nullptr) num = max(num, mx(cur->left, l, mid, lq, rq));
    if(cur->right != nullptr) num = max(num, mx(cur->right, mid+1, r, lq, rq));
    return num;
}
