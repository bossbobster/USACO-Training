#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n, total = 0;
char board[18][18];
set<string> fi;
set<string> se;
set<size_t> used;
string locl;

void first(int r, int c, string s)
{
    if(s.length() == n - 1)
    {
        s.push_back(board[r][c]);
        s.push_back(r+'a');
        fi.insert(s);
        return;
    }
    first(r + 1, c, s + board[r][c]);
    first(r, c + 1, s + board[r][c]);
}
void second(int r, int c, string s)
{
    if(s.length() == n - 1)
    {
        s.push_back(board[r][c]);
        s.push_back(r+'a');
        se.insert(s);
        return;
    }
    second(r - 1, c, s + board[r][c]);
    second(r, c - 1, s + board[r][c]);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> board[i][j];
    first(0, 0, "");
    second(n - 1, n - 1, "");
    
    for(set<string>::iterator it = fi.begin(); it != fi.end(); ++ it)
    {
        locl = (string)(*it);
        string locl1 = locl.substr(0, locl.length()-1);
        size_t h1 = hash<string>{}(locl1.substr(locl1.size()/3, locl1.size()/1.2)+ locl1);
        if(se.find(locl) != se.end() && (used.find(h1) == used.end()))
        {
            total ++;
            used.insert(h1);
        }
    }
    cout << total << endl;
}
