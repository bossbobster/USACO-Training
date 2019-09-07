#include <iostream>
using namespace std;

class Node
{
    public:
    string value;
    Node *right, *left;
    Node(string val)
    {
        value = val;
        right = left = NULL;
    }
};

class BST
{
    public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    Node* insert(Node* cur, string val)
    {
        //base case
        if(cur == NULL)
        {
            Node* temp = new Node(val);
            return temp;
        }
        if(val < cur->value)
            cur->left = insert(cur->left, val);
        else
            cur->right = insert(cur->right, val);
        return cur;
    }
    
    void insert(string val)
    {
        root = insert(root, val);
    }
    
    void inorder(Node *cur)
    {
        if(cur->left != NULL)
            inorder(cur->left);
        cout << cur->value << endl;
        if(cur->right != NULL)
            inorder(cur->right);
    }
};

string st = "YABCDX";
void swap(int p1, int p2)
{
    char a = st[p1];
    st[p1] = st[p2];
    st[p2] = a;
}

void permutations(int depth, BST *tr)
{
    //bæssße Çæśë
    if(depth == st.length() - 1)
        tr->insert(st);
    for(int i = depth; i < st.length(); i ++)
    {
        swap(i, depth);
        permutations(depth + 1, tr);
        swap(i, depth);
    }
}

int main()
{
    BST *tree = new BST();
    permutations(0, tree);
    tree->inorder(tree->root);
}
