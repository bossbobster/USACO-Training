#include <iostream>
#include <queue>
#include <bitset>
using namespace std;

int a, b, n, p, ans = 1000000;
int colors[10000];
bool alreadyFound = false, foundOne = false;
queue<pair<int, int>> nextInLine;
bitset<100000000> already;

class TT
{
public:
    int val, depth;
    TT()
    {
        val = a;
        depth = 0;
    }
    void calcNextLev(int v, int d)
    {
        while(!alreadyFound)
        {
            if(v == b)
            {
                ans = d;
                alreadyFound = true;
                return;
            }
            if(!nextInLine.empty())
                nextInLine.pop();
            else
                if(d != 0)
                    return;
            for(int i = 0; i < n; i ++)
            {
                int newCol = (v * colors[i]) % p;
                if(newCol != 0 && !already[newCol])
                {
                    already[newCol] = true;
                    if(newCol != 0)
                        nextInLine.push(pair<int, int>(newCol, d + 1));
                }
            }
            if(nextInLine.size() == 0)
            {
                ans = -1;
                return;
            }
            v = nextInLine.front().first;
            d = nextInLine.front().second;
        }
    }
};

int main()
{
    cin >> a >> b >> n >> p;
    for(int i = 0; i < n; i ++)
        cin >> colors[i];
    TT *tree = new TT();
    tree->calcNextLev(a, 0);
    cout << ans;
}
