#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("billboard.in");
ofstream fout("billboard.out");

bool billboard[2010][2010];
int b1[4], b2[4], truck[4];
int main()
{
    int total = 0;
    for(int i = 0; i < 4; i ++) fin >> b1[i];
    for(int i = 0; i < 4; i ++) fin >> b2[i];
    for(int i = 0; i < 4; i ++) fin >> truck[i];
    for(int i = b1[0]; i < b1[2]; i ++)
        for(int j = b1[1]; j < b1[3]; j ++)
            billboard[i + 1000][j + 1000] = true;
    for(int i = b2[0]; i < b2[2]; i ++)
        for(int j = b2[1]; j < b2[3]; j ++)
            billboard[i + 1000][j + 1000] = true;
    for(int i = truck[0]; i < truck[2]; i ++)
        for(int j = truck[1]; j < truck[3]; j ++)
            billboard[i + 1000][j + 1000] = false;
    for(int i = 0; i <= 2000; i ++)
        for(int j = 0; j <= 2000; j ++)
            if(billboard[i][j])
                total ++;
    fout << total;
}
