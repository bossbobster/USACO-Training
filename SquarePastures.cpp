//Bronze

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("square.in");
ofstream fout("square.out");

int rects[2][4];
int maxs[2] = {-1000000000, -1000000000};
int mins[2] = {1000000000, 1000000000};
int main()
{
    int l;
    fin >> rects[0][0] >> rects[1][0] >> rects[0][1] >> rects[1][1] >> rects[0][2] >> rects[1][2] >> rects[0][3] >> rects[1][3];
    for(int i = 0; i < 2; i ++)
        for(int j = 0; j < 4; j ++)
        {
            if(rects[i][j] > maxs[i]) maxs[i] = rects[i][j];
            if(rects[i][j] < mins[i]) mins[i] = rects[i][j];
        }
    l = max(abs(maxs[0] - mins[0]), abs(maxs[1] - mins[1]));
    fout << l * l << endl;
}
