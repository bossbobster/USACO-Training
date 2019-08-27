#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

ifstream fin("namenum.in");
ofstream fout("namenum.out");

ifstream readfile;

string names[5000];
char letters[8][3] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y'}};
int main()
{
    readfile.open("dict.txt");
    if(!readfile.is_open())
    {
        exit(EXIT_FAILURE);
    }
    int nl=0;
    while (!readfile.eof())
    {
        readfile >> names[nl++];
    }
    readfile.close();
    
    string code;
    fin >> code;
    int cnt = 0;
    int len = 0;
    for(int i = 0; i < nl; i ++)
    {
        if(names[i].length() == code.length())
        {
            names[cnt] = names[i];
            cnt ++;
            len ++;
        }
    }
    //fout << len;
    int nextLen = len;
    for(int i = 0; i < code.length(); i ++)
    {
        cnt = 0;
        nextLen = len;
        len = 0;
        for(int j = 0; j < nextLen; j ++)
        {
            if(names[j][i] == letters[(code[i] - '0') - 2][0] || names[j][i] == letters[(code[i] - '0') - 2][1] || names[j][i] == letters[(code[i] - '0') - 2][2])
            {
                //fout << names[j] << " " << names[j][i] << " " << code[i] << endl;
                names[cnt] = names[j];
                len ++;
                cnt ++;
            }
        }
    }
    //fout << len;
    for(int i = 0; i < len; i ++)
    {
        fout << names[i] << endl;
    }
    if(len == 0)
    {
        fout << "NONE" << endl;
    }
}
