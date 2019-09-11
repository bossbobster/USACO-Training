#include <iostream>
#include <algorithm>
using namespace std;

int chords[20000];
int sequence[10];
int cur[10];
int differences[9];
int positions[20000];
int main()
{
    int n, c, cnt = 0;
    bool correct = true;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> chords[i];
    cin >> c;
    for(int i = 0; i < c; i ++)
        cin >> sequence[i];
    sort(sequence, sequence + c);
    for(int i = 1; i < c; i ++)
        differences[i - 1] = sequence[i] - sequence[i - 1];
    for(int i = 0; i <= n - c; i ++)
    {
        correct = true;
        for(int j = 0; j < c; j ++)
            cur[j] = chords[j + i];
        sort(cur, cur + c);
        for(int j = 1; j < c; j ++)
            if(cur[j] - cur[j - 1] != differences[j - 1])
            {
                correct = false;
                break;
            }
        if(correct)
            positions[cnt ++] = i + 1;
    }
    cout << cnt << endl;
    for(int i = 0; i < cnt; i ++)
        cout << positions[i] << endl;
}
