#include <iostream>
#include <string>
using namespace std;

int answers[20][20];
string dna[40];
int main()
{
    int m, f;
    bool child = true;
    cin >> m >> f;
    for(int i = 0; i < m + f; i ++)
        cin >> dna[i];
    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < f; j ++)
        {
            for(int k = 0; k < m + f; k ++)
            {
                child = true;
                if(k == i || k == j + m)
                    continue;
                for(int l = 0; l < 25; l ++)
                {
                    if(dna[k][l] != dna[i][l] && dna[k][l] != dna[j + m][l])
                    {
                        child = false;
                        break;
                    }
                }
                if(child)
                    answers[i][j] ++;
            }
        }
    }
    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < f; j ++)
        {
            cout << answers[i][j] << " ";
        }
        cout << endl;
    }
}
