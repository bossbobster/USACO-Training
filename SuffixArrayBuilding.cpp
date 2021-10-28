int n, idxAll, num, pw;
piii all[2000010], other[2000010];
vector<piii> all2[2000010];
string st;
int pre[2000010][23];
void suf()
{
    for(int i = 0; i < n; i ++)
        pre[i][0] = st[i]-'a';
    for(int i = 1; i <= pw; i ++)
    {
        idxAll = 0;
        for(int j = 0; j < n; j ++)
            all[idxAll++] = {{pre[j][i-1], pre[j+(1<<(i-1))][i-1]}, j};
        for(int j = 0; j < n; j ++)
            all2[j].clear();
        for(int j = 0; j < n; j ++)
            all2[all[j].f.s].push_back(all[j]);
        idxAll = 0;
        for(int j = 0; j < n; j ++)
            for(auto it : all2[j])
                other[idxAll++] = it;
        for(int j = 0; j < n; j ++)
            all2[j].clear();
        for(int j = 0; j < n; j ++)
            all2[other[j].f.f].push_back(other[j]);
        idxAll = 0;
        for(int j = 0; j < n; j ++)
            for(auto it : all2[j])
                all[idxAll++] = it;
        num = 0;
        for(int j = 0; j < n; j ++)
            pre[all[j].s][i] = (j != 0 && all[j].f.f == all[j-1].f.f && all[j].f.s == all[j-1].f.s)?pre[all[j-1].s][i]:num++;
    }
}
int main()
{
    input();
    cin >> st;
    n = (int)st.length();
    st.reserve(n*2);
    st += st;
    pw = log2(n*2);
    suf();
}
