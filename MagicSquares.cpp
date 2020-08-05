#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<string, string> pss;
typedef pair<pair<string, string>, int> pssi;

string s = "        ", og, ans, a, b, c;
int first[8];
map<string, int> m;
queue<pssi> nextInLine;
int main()
{
    int d = 0;
    for(int i = 0; i < 8; i ++)
        cin >> first[i];
    for(int i = 0; i < 4; i ++) s[i] = (first[i] + '0');
    for(int i = 7; i >= 4; i --) s[i] = (first[11 - i] + '0');
    og = s;
    nextInLine.push(pssi(pss("12348765", ""), 0));
    while(!nextInLine.empty())
    {
        s = nextInLine.front().first.first;
        ans = nextInLine.front().first.second;
        d = nextInLine.front().second;
        nextInLine.pop();
        if(m.find(s) != m.end()) continue;
        m[s] = d;
        if(s == og) break;
        a = s.substr(4, 4) + s.substr(0, 4);
        b = s.substr(3, 1) + s.substr(0, 3) + s.substr(7, 1) + s.substr(4, 3);
        c = s.substr(0, 1) + s.substr(5, 1) + s.substr(1, 1) + s.substr(3, 1) + s.substr(4, 1) + s.substr(6, 1) + s.substr(2, 1) + s.substr(7, 1);
        nextInLine.push(pssi(pss(a, ans + "A"), d + 1));
        nextInLine.push(pssi(pss(b, ans + "B"), d + 1));
        nextInLine.push(pssi(pss(c, ans + "C"), d + 1));
     }
    cout << d << "\n" << ans << "\n";
}
