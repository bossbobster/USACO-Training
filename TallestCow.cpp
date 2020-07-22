#include <iostream>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int prefix[10010];
set<pair<int, int>> s;
int main()
{
    int n, in, h, r, a, b;
    cin >> n >> in >> h >> r;
    for(int i = 0; i < r; i ++)
    {
        cin >> a >> b;
        if(a > b) swap(a, b);
        if(s.find(pair<int, int>(a, b)) != s.end()) continue;
        prefix[a] ++;
        prefix[b - 1] --;
        s.insert(pair<int, int>(a, b));
    }
    for(int i = 1; i < n; i ++)
        prefix[i] += prefix[i - 1];
    for(int i = 0; i < n; i ++)
        cout << h - prefix[i] << "\n";
}
