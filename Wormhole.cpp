/*
 PROB: wormhole
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define MAX_N 13

ifstream fin("wormhole.in");
ofstream fout("wormhole.out");

struct wormh
{
    u_long x, y;
    int next = -1;
    int partner = -1;
};

int n, total = 0;
wormh holes[MAX_N];

bool sorting(wormh w1, wormh w2)
{
    if(w1.y != w2.y)
        return (w1.y < w2.y);
    return (w1.x < w2.x);
}

void calculateNext()
{
    for(int i = 0; i < n - 1; i ++)
    {
        if(holes[i].y == holes[i + 1].y)
            holes[i].next = i + 1;
    }
}

bool checkCycle()
{
    bool cycle = true;
    wormh cur;
    for(int i = 0; i < n; i ++)
    {
        cur = holes[i];
        cycle = true;
        for(int j = 0; j < n; j ++)
        {
            cur = holes[cur.partner];
            if(cur.next != -1)
            {
                cur = holes[cur.next];
                continue;
            }
            cycle = false;
            break;
        }
        if(cycle == true)
            break;
    }
    return cycle;
}

int solve(int depth)
{
    //base case
    if(depth == n - 1)
    {
        if(checkCycle())
            total ++;
    }
    
    //special case
    if(holes[depth].partner != -1)
        return solve(depth + 1);
    
    for(int i = depth + 1; i < n; i ++)
    {
        if(holes[i].partner != -1)
            continue;
        holes[depth].partner = i;
        holes[i].partner = depth;
        solve(depth + 1);
        holes[i].partner = -1;
        holes[depth].partner = -1;
    }
    return total;
}

int main()
{
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> holes[i].x >> holes[i].y;
    }
    sort(holes, holes + n, sorting);
    calculateNext();
    fout << solve(0) << endl;
}

/*
 Executing...
 Test 1: TEST OK [0.004 secs, 1392 KB]
 Test 2: TEST OK [0.004 secs, 1456 KB]
 Test 3: TEST OK [0.000 secs, 1408 KB]
 Test 4: TEST OK [0.004 secs, 1328 KB]
 Test 5: TEST OK [0.004 secs, 1364 KB]
 Test 6: TEST OK [0.004 secs, 1412 KB]
 Test 7: TEST OK [0.004 secs, 1452 KB]
 Test 8: TEST OK [0.007 secs, 1416 KB]
 Test 9: TEST OK [0.007 secs, 1392 KB]
 Test 10: TEST OK [0.004 secs, 1400 KB]
 */
