#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct stage
{
    string s;
    int d;
};

int distance(string ss1, string ss2)
{
    int dist = 0;
    for(int i = 0; i < ss1.length(); i ++)
        if(ss1[i] != ss2[i]) 
            dist ++;
    return dist;
}

vector<string> dict;
queue<stage> nextInLine;
set<string> visited;
int main()
{
    string s1, s2, s;
    int d;
    cin >> s1 >> s2;
    while(cin >> s)
        if(s.length() == s1.length())
            dict.push_back(s);
    nextInLine.push({s1, 0});
    while(!nextInLine.empty())
    {
        s = nextInLine.front().s;
        d = nextInLine.front().d;
        if(visited.find(s) != visited.end()) { nextInLine.pop(); continue; }
        visited.insert(s);
        if(s == s2)
        {
            cout << d << endl;
            break;
        }
        for(int i = 0; i < dict.size(); i ++)
            if(distance(s, dict[i]) == 1)
                nextInLine.push({dict[i], d + 1});
        nextInLine.pop();
    }
}
