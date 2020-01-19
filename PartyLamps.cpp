#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> off;
vector<int> on;
vector<string> pos;
set<int> elim;
string cur = "";
vector<string> ans;
int main()
{
    int n, c, num = 0, idx = 1;
    cin >> n >> c >> num;
    while(num != -1) { on.push_back(num); cin >> num; }
    cin >> num;
    while(num != -1) { off.push_back(num); cin >> num; }
    for(int i = 0; i < n; i ++) cur += "1";
    pos.push_back(cur);
    if(c >= 2)
    {
        for(int i = 0; i < n; i ++) cur[i] = '0';
        pos.push_back(cur);
        for(int i = 0; i < n; i ++)
            if(i % 2 == 0) cur[i] = '1';
        pos.push_back(cur);
        for(int i = 0; i < n; i ++) 
        {
            if(cur[i] == '0') cur[i] = '1'; else cur[i] = '0';
        }
        pos.push_back(cur);
        for(int i = 2; i < n; i ++)
        {
            if(((i + 1) / 3) % 2 == 1) { if(cur[i] == '0') cur[i] = '1'; else cur[i] = '0'; }
        }
        pos.push_back(cur);
        for(int i = 0; i < n; i ++) 
        {
            if(cur[i] == '0') cur[i] = '1'; else cur[i] = '0';
        }
        pos.push_back(cur);
        for(int i = 0; i < n; i ++)
        {
            if(i % 2 == 0) { if(cur[i] == '0') cur[i] = '1'; else cur[i] = '0'; }
        }
        pos.push_back(cur);
        for(int i = 0; i < n; i ++) 
        {
            if(cur[i] == '0') cur[i] = '1'; else cur[i] = '0';
        }
        pos.push_back(cur);
    }
    for(int i = 0; i < on.size(); i ++)
        for(int j = 0; j < pos.size(); j ++)
            if(pos[j][on[i] - 1] == '0')
                elim.insert(j);
    for(int i = 0; i < off.size(); i ++)
        for(int j = 0; j < pos.size(); j ++)
            if(pos[j][off[i] - 1] == '1')
                elim.insert(j);
    for(int i = 0; i < pos.size(); i ++)
        if(elim.find(i) == elim.end())
            ans.push_back(pos[i]);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i ++) cout << ans[i] << "\n";
    if(ans.empty()) cout << "IMPOSSIBLE" << "\n";
}
