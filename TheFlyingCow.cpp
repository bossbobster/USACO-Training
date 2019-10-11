#include <iostream>
#include <queue>
#include <bitset>

using namespace std;

int n, ans = 1000000;
bool alreadyFound = false;
queue<pair<int, int>> nextInLine;
bitset<1000030> already;

class TT
{
public:
    int val, depth;
    TT()
    {
        val = 1;
        depth = 0;
    }
    void calcNextLev(int v, int d)
    {
        while(!alreadyFound){
            if(v == n)
            {
                ans = d;
                alreadyFound = true;
                return;
            }
            already[v] = true;;
            if(!nextInLine.empty())
                nextInLine.pop();
            else
                if(d != 0)
                    return;
            if(v > 1)
                if(!already[v - 1])
                    nextInLine.push(pair<int, int>(v - 1, d + 1));
            if(v < n)
            {
                if(v * 3 < n + 2)
                    if(!already[v * 3])
                        nextInLine.push(pair<int, int>(v * 3, d + 1));
                if(!already[v + 1])
                    nextInLine.push(pair<int, int>(v + 1, d + 1));
            }
            v = nextInLine.front().first;
            d = nextInLine.front().second;
        }
    }
};

int main()
{
    cin >> n;
    TT *tree = new TT();
    tree->calcNextLev(tree->val, tree->depth);
    cout << ans;
}
