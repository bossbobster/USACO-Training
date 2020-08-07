#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

pii cows[410];
set<double> slopes;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> cows[i].first >> cows[i].second;
    for(int i = 0; i < n; i ++)
        for(int j = i + 1; j < n; j ++)
        {
            if(cows[i].first == cows[j].first) { slopes.insert(1000000000); continue; }
            if(cows[i].second == cows[j].second) { slopes.insert(0); continue; }
            slopes.insert((double)(cows[i].second - cows[j].second) / (double)(cows[i].first - cows[j].first));
        }
    cout << slopes.size() << "\n";
}
