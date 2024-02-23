struct node
{
    node* nx[26];
    int cnt = 0;
};
struct trie
{
    node* root = nullptr, *cur;
    trie()
    {
        root = new node();
    }
    void add(string st)
    {
        cur = root;
        for(auto it : st)
        {
            if(cur->nx[it-'a'] == nullptr)
                cur->nx[it-'a'] = new node();
            cur = cur->nx[it-'a'];
        }
        cur->cnt ++;
    }
    bool go(char c)
    {
        if(cur->nx[c-'a'] == nullptr) return false;
        cur = cur->nx[c-'a'];
        return true;
    }
    bool has(string st)
    {
        cur = root;
        for(auto it : st)
        {
            if(cur->nx[it-'a'] == nullptr)
                return false;
            cur = cur->nx[it-'a'];
        }
        return cur->cnt > 0;
    }
};
