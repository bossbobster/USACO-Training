/*
 PROB: milk3
 LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

ifstream fin("milk3.in");
ofstream fout("milk3.out");

int previous, to, idx = 0;
short caps[3];
short vals[3];
bool visited[30000];
set<int> possible;

struct cow
{
    int vals[3];
    int prev, to;
};

queue<cow> nextInLine;

void findAll()
{
    do
    {
        vals[0] = nextInLine.front().vals[0];
        vals[1] = nextInLine.front().vals[1];
        vals[2] = nextInLine.front().vals[2];
        previous = nextInLine.front().prev;
        to = nextInLine.front().to;
        if(vals[0] == 0)
            possible.insert(vals[2]);
        if(vals[previous] < caps[to] - vals[to])
        {
            vals[to] += vals[previous];
            vals[previous] = 0;
        }
        else
        {
            vals[previous] -= (caps[to] - vals[to]);
            vals[to] = caps[to];
        }
        if(visited[vals[0] * 441 + vals[1] * 21 + vals[2]])
        {
            nextInLine.pop();
            continue;
        }
        visited[vals[0] * 441 + vals[1] * 21 + vals[2]] = true;
        nextInLine.push({{vals[0], vals[1], vals[2]}, 0, 1});
        nextInLine.push({{vals[0], vals[1], vals[2]}, 0, 2});
        nextInLine.push({{vals[0], vals[1], vals[2]}, 1, 0});
        nextInLine.push({{vals[0], vals[1], vals[2]}, 1, 2});
        nextInLine.push({{vals[0], vals[1], vals[2]}, 2, 0});
        nextInLine.push({{vals[0], vals[1], vals[2]}, 2, 1});
    } while(!nextInLine.empty());
}

int main()
{
    fin >> caps[0] >> caps[1] >> caps[2];
    vals[2] = caps[2];
    nextInLine.push({{0, 0, caps[2]}, 2, 0});
    nextInLine.push({{0, 0, caps[2]}, 2, 1});
    findAll();
    for(set<int>::iterator it = possible.begin(); it != possible.end(); ++ it)
    {
        idx ++;
        fout << *it;
        if(idx == possible.size()) fout << endl;
        else fout << " ";
    }
}
