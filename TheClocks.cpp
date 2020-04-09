#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct stage
{
    int arr[9];
    vector<int> steps;
};

stage c;
bool visited[262200];
queue<stage> nextInLine;

void A() { c.arr[0] ++; c.arr[0] %= 4; }
void B() { c.arr[1] ++; c.arr[1] %= 4; }
void C() { c.arr[2] ++; c.arr[2] %= 4; }
void D() { c.arr[3] ++; c.arr[3] %= 4; }
void E() { c.arr[4] ++; c.arr[4] %= 4; }
void F() { c.arr[5] ++; c.arr[5] %= 4; }
void G() { c.arr[6] ++; c.arr[6] %= 4; }
void H() { c.arr[7] ++; c.arr[7] %= 4; }
void I() { c.arr[8] ++; c.arr[8] %= 4; }

void one() { A(); B(); D(); E(); }
void two() { A(); B(); C();}
void three() { B(); C(); E(); F(); }
void four() { A(); D(); G();}
void five() { B(); D(); E(); F(); H(); }
void six() { C(); F(); I(); }
void seven() { D(); E(); G(); H(); }
void eight() { G(); H(); I();}
void nine() { E(); F(); H(); I(); }

int main()
{
    for(int i = 0; i < 9; i ++)
    {
        cin >> c.arr[i];
        c.arr[i] /= 3; c.arr[i] %= 4;
    }
    nextInLine.push(c);
    while(!nextInLine.empty())
    {
        for(int i = 0; i < 9; i ++) c.arr[i] = nextInLine.front().arr[i];
        c.steps.clear();
        for(int i = 0; i < nextInLine.front().steps.size(); i ++) c.steps.push_back(nextInLine.front().steps[i]);
        if(visited[c.arr[0] * 1 + c.arr[1] * 4 + c.arr[2] * 16 + c.arr[3] * 64 + c.arr[4] * 256 + c.arr[5] * 1024 + c.arr[6] * 4096 + c.arr[7] * 16384 + c.arr[8] * 65536]) { nextInLine.pop(); continue; }
        visited[c.arr[0] * 1 + c.arr[1] * 4 + c.arr[2] * 16 + c.arr[3] * 64 + c.arr[4] * 256 + c.arr[5] * 1024 + c.arr[6] * 4096 + c.arr[7] * 16384 + c.arr[8] * 65536] = true;
        if(c.arr[0] == 0 && c.arr[1] == 0 && c.arr[2] == 0 && c.arr[3] == 0 && c.arr[4] == 0 && c.arr[5] == 0 && c.arr[6] == 0 && c.arr[7] == 0 && c.arr[8] == 0)
            break;
        one(); c.steps.push_back(1); if(!visited[c.arr[0] * 1 + c.arr[1] * 4 + c.arr[2] * 16 + c.arr[3] * 64 + c.arr[4] * 256 + c.arr[5] * 1024 + c.arr[6] * 4096 + c.arr[7] * 16384 + c.arr[8] * 65536]) nextInLine.push(c); 
        c.steps.pop_back();
        for(int i = 0; i < 9; i ++) c.arr[i] = nextInLine.front().arr[i];
        two(); c.steps.push_back(2); if(!visited[c.arr[0] * 1 + c.arr[1] * 4 + c.arr[2] * 16 + c.arr[3] * 64 + c.arr[4] * 256 + c.arr[5] * 1024 + c.arr[6] * 4096 + c.arr[7] * 16384 + c.arr[8] * 65536]) nextInLine.push(c); 
        c.steps.pop_back();
        for(int i = 0; i < 9; i ++) c.arr[i] = nextInLine.front().arr[i];
        three(); c.steps.push_back(3); if(!visited[c.arr[0] * 1 + c.arr[1] * 4 + c.arr[2] * 16 + c.arr[3] * 64 + c.arr[4] * 256 + c.arr[5] * 1024 + c.arr[6] * 4096 + c.arr[7] * 16384 + c.arr[8] * 65536]) nextInLine.push(c); 
        c.steps.pop_back();
        for(int i = 0; i < 9; i ++) c.arr[i] = nextInLine.front().arr[i];
        four(); c.steps.push_back(4); if(!visited[c.arr[0] * 1 + c.arr[1] * 4 + c.arr[2] * 16 + c.arr[3] * 64 + c.arr[4] * 256 + c.arr[5] * 1024 + c.arr[6] * 4096 + c.arr[7] * 16384 + c.arr[8] * 65536]) nextInLine.push(c); 
        c.steps.pop_back();
        for(int i = 0; i < 9; i ++) c.arr[i] = nextInLine.front().arr[i];
        five(); c.steps.push_back(5); if(!visited[c.arr[0] * 1 + c.arr[1] * 4 + c.arr[2] * 16 + c.arr[3] * 64 + c.arr[4] * 256 + c.arr[5] * 1024 + c.arr[6] * 4096 + c.arr[7] * 16384 + c.arr[8] * 65536]) nextInLine.push(c); 
        c.steps.pop_back();
        for(int i = 0; i < 9; i ++) c.arr[i] = nextInLine.front().arr[i];
        six(); c.steps.push_back(6); if(!visited[c.arr[0] * 1 + c.arr[1] * 4 + c.arr[2] * 16 + c.arr[3] * 64 + c.arr[4] * 256 + c.arr[5] * 1024 + c.arr[6] * 4096 + c.arr[7] * 16384 + c.arr[8] * 65536]) nextInLine.push(c); 
        c.steps.pop_back();
        for(int i = 0; i < 9; i ++) c.arr[i] = nextInLine.front().arr[i];
        seven(); c.steps.push_back(7); if(!visited[c.arr[0] * 1 + c.arr[1] * 4 + c.arr[2] * 16 + c.arr[3] * 64 + c.arr[4] * 256 + c.arr[5] * 1024 + c.arr[6] * 4096 + c.arr[7] * 16384 + c.arr[8] * 65536]) nextInLine.push(c); 
        c.steps.pop_back();
        for(int i = 0; i < 9; i ++) c.arr[i] = nextInLine.front().arr[i];
        eight(); c.steps.push_back(8); if(!visited[c.arr[0] * 1 + c.arr[1] * 4 + c.arr[2] * 16 + c.arr[3] * 64 + c.arr[4] * 256 + c.arr[5] * 1024 + c.arr[6] * 4096 + c.arr[7] * 16384 + c.arr[8] * 65536]) nextInLine.push(c); 
        c.steps.pop_back();
        for(int i = 0; i < 9; i ++) c.arr[i] = nextInLine.front().arr[i];
        nine(); c.steps.push_back(9); if(!visited[c.arr[0] * 1 + c.arr[1] * 4 + c.arr[2] * 16 + c.arr[3] * 64 + c.arr[4] * 256 + c.arr[5] * 1024 + c.arr[6] * 4096 + c.arr[7] * 16384 + c.arr[8] * 65536]) nextInLine.push(c); 
        c.steps.pop_back();
        for(int i = 0; i < 9; i ++) c.arr[i] = nextInLine.front().arr[i];
        nextInLine.pop();
    }
    for(int i = 0; i < c.steps.size(); i ++)
        cout << c.steps[i] << " ";
    cout << endl;
}
