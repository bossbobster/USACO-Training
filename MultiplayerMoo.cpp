#include <iostream>
#include <fstream>
#include <queue>
#include <bitset>
#include <set>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
#define ppp pair<pii, pii>

struct coordinate
{
    int r, c;
};

ifstream fin("multimoo.in");
ofstream fout("multimoo.out");

queue<coordinate> nextInLine;
bitset<260 * 260> visited;
int board[260][260];
set<pii> pairs;
set<ppp> compPairs;
int main()
{
    int n, row, column, num, cur = 0, maxN = 0, cur1 = 0, maxN1 = 0;
    pii nums;
    fin >> n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            fin >> board[i][j];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            if(visited[i * n + j]) continue;
            num = board[i][j];
            cur = 0;
            nextInLine.push({i, j});
            do
            {
                row = nextInLine.front().r;
                column = nextInLine.front().c;
                if(row < 0||row >= n||column < 0||column >= n)
                {
                    nextInLine.pop();
                    continue;
                }
                if(visited[row * n + column])
                {
                    nextInLine.pop();
                    continue;
                }
                if(board[row][column] != num)
                {
                    
                    if(pairs.find(pii(board[row][column], num)) == pairs.end() && pairs.find(pii(num, board[row][column])) == pairs.end())
                    {
                        pairs.insert(pii(num, board[row][column]));
                        compPairs.insert(ppp(pii(num, board[row][column]), pii(row, column)));
                    }
                    nextInLine.pop();
                    continue;
                }
                cur ++;
                visited[row * n + column] = true;
                nextInLine.push({row, column + 1});
                nextInLine.push({row, column - 1});
                nextInLine.push({row + 1, column});
                nextInLine.push({row - 1, column});
                maxN = max(maxN, cur);
                nextInLine.pop();
            }while(!nextInLine.empty());
        }
    for(set<ppp>::iterator it = compPairs.begin(); it != compPairs.end(); ++it)
    {
        visited.reset();
        nums = pii(it->first.first, it->first.second);
        cur1 = 0;
        nextInLine.push({it->second.first, it->second.second});
        do
        {
            row = nextInLine.front().r;
            column = nextInLine.front().c;
            if((board[row][column] != nums.first && board[row][column] != nums.second) ||row < 0||row >= n||column < 0||column >= n)
            {
                nextInLine.pop();
                continue;
            }
            if(visited[row * n + column])
            {
                nextInLine.pop();
                continue;
            }
            cur1 ++;
            visited[row * n + column] = true;
            nextInLine.push({row, column + 1});
            nextInLine.push({row, column - 1});
            nextInLine.push({row + 1, column});
            nextInLine.push({row - 1, column});
            maxN1 = max(maxN1, cur1);
            nextInLine.pop();
        }while(!nextInLine.empty());
    }
    fout << maxN << endl << maxN1 << endl;
}
