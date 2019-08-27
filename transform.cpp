#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("transform.in");
ofstream fout("transform.out");

char shape[1000][1000];
char shape1[1000][1000];
char shape2[1000][1000];
char shape3[1000][1000];
char shape4[1000][1000];
char shape5v1[1000][1000];
char shape5v2[1000][1000];
char shape5v3[1000][1000];
char changedshape[1000][1000];
bool answers[7];
int main()
{
    for(int i = 0; i < 7; i ++)
    {
        answers[i] = true;
    }
    int n = 0, answer = 0;
    char cur = ' ';
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            fin >> cur;
            shape[i][j] = cur;
            shape1[j][n - i - 1] = cur;
            shape2[n - i - 1][n - j - 1] = cur;
            shape3[n - j - 1][i] = cur;
            shape4[i][n - j - 1] = cur;
            shape5v1[n - j - 1][n - i - 1] = cur;
            shape5v2[n - i - 1][j] = cur;
            shape5v3[j][i] = cur;
        }
    }
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            fin >> cur;
            changedshape[i][j] = cur;
            if(changedshape[i][j] != shape1[i][j])
            {
                answers[0] = false;
            }
            if(changedshape[i][j] != shape2[i][j])
            {
                answers[1] = false;
            }
            if(changedshape[i][j] != shape3[i][j])
            {
                answers[2] = false;
            }
            if(changedshape[i][j] != shape4[i][j])
            {
                answers[3] = false;
            }
            if(changedshape[i][j] != shape5v1[i][j])
            {
                answers[4] = false;
            }
            if(changedshape[i][j] != shape5v2[i][j])
            {
                answers[5] = false;
            }
            if(changedshape[i][j] != shape5v3[i][j])
            {
                answers[6] = false;
            }
        }
    }
    for(int i = 6; i >= 0; i --)
    {
        if(answers[i])
        {
            answer = i + 1;
        }
    }
    if(answer >= 5)
    {
        answer = 5;
    }
    if(answer == 0)
    {
        answer = 7;
    }
    fout << answer << endl;
}
