#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define pii pair<int, int>
#define pli pair<unsigned long long, int>

pii cows[1010];
pii chairs[1010];
set<int> usedCows;
set<int> finalCows;
//contains distance from each chair to each cow and cow index
pli distancesChairs[1010][1010];

unsigned long long dist(pii co, pii ch)
{
    long long part1 = (co.first - ch.first);
    long long part2 = (co.second - ch.second);
    unsigned long long ans = (part1 * part1) + (part2 * part2);
    return ans;
}

bool cpr(pli p1, pli p2)
{
    if(p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

int main()
{
    int n, m, idx = 0;
    cin >> n >> m;
    if(n == m)
        cout << 0;
    else
    {
        for(int i = 0; i < n; i ++)
        {
            cin >> cows[i].first >> cows[i].second;
            finalCows.insert(i + 1);
        }
        for(int i = 0; i < m; i ++)
            cin >> chairs[i].first >> chairs[i].second;
        //calculate all the distances between every chair and cow and sort the distances from every chair
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < n; j ++)
                distancesChairs[i][j] = pli(dist(cows[j], chairs[i]), j);
            sort(distancesChairs[i], distancesChairs[i] + n, cpr);
        }
        //selects the closest cow to each chair
        for(int i = 0; i < m; i ++)
        {
            idx = 0;
            while(usedCows.find(distancesChairs[i][idx].second) != usedCows.end()) idx ++;
            usedCows.insert(distancesChairs[i][idx].second);
            finalCows.erase(distancesChairs[i][idx].second + 1);
        }
        for(set<int>::iterator it = finalCows.begin(); it != finalCows.end(); ++ it)
            cout << *it << endl;
    }
}
