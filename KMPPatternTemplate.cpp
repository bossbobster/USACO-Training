int kmp[1000010];
int main()
{
    string st, pat;
    int n, x;
    cin >> st >> pat;
    st = pat + st;
    n = (int)st.length();
    kmp[0] = -1; kmp[1] = 0;
    for(int i = 1; i < n; i ++)
    {
        x = kmp[i];
        while(x != -1 && st[x] != st[i])
            x = kmp[x];
        kmp[i+1] = x+1;
        if(kmp[i+1] > pat.length())
            kmp[i+1] = kmp[kmp[i+1]];
    }
    int ans = 0;
    for(int i = (int)pat.length()*2; i <= (int)st.length(); i ++)
        if(kmp[i] == pat.length())
            ans ++;
    cout << ans << '\n';
}
