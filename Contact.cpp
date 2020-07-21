#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

string all = "";
unordered_map<string, int> m;
vector<pair<int, string>> ord;
bool comp(pair<int, string> p1, pair<int, string> p2)
{
    if(p1.first == p2.first)
    {
        if(p1.second.length() < p2.second.length()) return true;
        if(p2.second.length() < p1.second.length()) return false;
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}
int main()
{
    int a, b, n, idx = 1, cnt = 1;
    string s;
    cin >> a >> b >> n;
    while(cin >> s)
        all += s;
    for(int i = a; i <= b; i ++)
    {
        if(i > all.length()) break;
        for(int j = 0; j <= all.length() - i; j ++)
            if(i <= all.length() - j)
                m[all.substr(j, i)] ++;
    }
    for(unordered_map<string, int>::iterator it = m.begin(); it != m.end(); ++ it)
        ord.push_back(pair<int, string>(it->second, it->first));
    sort(ord.begin(), ord.end(), comp);
    cout << ord[0].first << "\n" << ord[0].second << " ";
    while(n >= 1 && idx < ord.size())
    {
        if(ord[idx].first != ord[idx - 1].first)
        {
            if(n == 1) break;
            if(cnt == 0) cout << ord[idx].first << "\n" << ord[idx].second << " ";
            else cout << "\n" << ord[idx].first << "\n" << ord[idx].second << " ";
            cnt = 1; idx ++; n --;
            continue;
        }
        if(cnt == 6)
        {
            cnt = 0;
            cout << "\n";
        }
        cout << ord[idx].second << " ";
        cnt ++;
        idx ++;
    }
}
