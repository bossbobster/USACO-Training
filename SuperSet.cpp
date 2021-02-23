// THIS IS NOT A USACO PROBLEM
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

struct ss
{
    // binary index tree (to mark elements)
    int bit[1000010]; // set this number to the max you will use
    // set (to store the numbers in order)
    set<int> nums;
    // the maximum element in the set (NOTE: this data structure works with marking in the BIT array, but you can make this better by using an unordered set to store all values that could appear inside of the set, but this will increase runtime by a high constant factor)
    int mx;
    // constructor
    ss(int maxEl)
    {
        mx = maxEl + 5;
    }
    int sum(int arr[], int idx)
    {
        int ans = 0;
        idx ++;
        if(idx > mx + 5) return -1;
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
    int bs(int l, int r, int idx)
    {
        int mid = (l + r) / 2;
        if(l == r) return mid + 1;
        if(l == r - 1)
        {
            if(sum(bit, r) == idx) return r + 1;
            return r;
        }
        if(sum(bit, mid) <= idx) return bs(mid, r, idx);
        return bs(l, mid - 1, idx);
    }
    // regular set functions
    set<int>::iterator find(int num) { return nums.find(num); }
    set<int>::iterator lower_bound(int num) { return nums.lower_bound(num); }
    set<int>::iterator upper_bound(int num) { return nums.upper_bound(num); }
    int size() { return (int)nums.size(); }
    set<int>::iterator begin() { return nums.begin(); }
    set<int>::iterator end() { return nums.end(); }
    bool empty() { return nums.empty(); }
    // slightly modified insert and erase functions to also mark stuff in BIT (still O(log n) though)
    void insert(int num)
    {
        if(nums.find(num) == nums.end())
            update(bit, num, 1, mx); // marks the element in the BIT if it doesn't already exist
        nums.insert(num);
    }
    void erase(int num)
    {
        if(nums.find(num) != nums.end())
            update(bit, num, -1, mx); // unmarks the element in the BIT if it exists in the set
        nums.erase(num);
    }
    // gets index (0-indexed) of a specific element in O(log n), returns -1 if element not in set
    int idx(int num)
    {
        if(nums.find(num) == nums.end())
            return -1;
        return sum(bit, num - 1);
    }
    // gets the iterator of the element at a specific index (0-indexed) in O((log n) * (log n)), returns end of set if idx is invalid
    set<int>::iterator at(int idx)
    {
        if(idx < 0 || idx >= nums.size())
            return nums.end();
        return nums.find(bs(0, mx, idx));
    }
};

int main()
{
    ss test = ss(1000);
    test.insert(1);
    test.insert(3);
    test.insert(5);
    test.insert(1);
    test.insert(9);
    test.insert(1000);
    cout << *test.at(1) << "\n";
    test.erase(3);
    cout << *test.at(1) << "\n";
    cout << test.idx(1) << "\n";
    cout << *test.at(-1) << "\n";
}
