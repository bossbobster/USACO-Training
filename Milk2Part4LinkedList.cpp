
/*
 PROB: milk2
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("milk2.in");
ofstream fout("milk2.out");


// Structure to represent a node in linked list
struct Node
{
    int low, high;
    Node *next;
};

// A utility function to create a new Interval Search Tree Node
Node *newNode(int min, int max)
{
    Node *temp = new Node;
    temp->low = min;
    temp->high = max;
    temp->next = NULL;
    return temp;
};

// A utility function to insert a new Interval in the linked list
Node *insert(Node *root, int mn, int mx)
{
    // Base case: LL is empty, new node becomes root
    if (root == NULL)
        return newNode(mn, mx);
    
    Node *originalRoot = root; //this will be the node on the right of the interval
    
    if (root->low > mx ){ //we need to insert node to the left
        Node *el = newNode(mn, mx);
        el->next = root;
        return el; //el will be new root
    }
    if (root->low == mx){ //we need to merge those two
        root->low = mn;
        return root;
    }
    if (root->high == mn){ //we need to merge those two
        root->high = mx;
        return root;
    }
    

    //search for the location of the first intersecting segment - root will contain it
    while (root->high <= mn && root->next != NULL)
    {
        //insert a node in between
        if(mn > root->high && mx < root->next->low)
        {
            Node *el = newNode(mn, mx);
            Node *temp = root->next;
            root->next = el;
            el->next = temp;
            return originalRoot;
        }
        root = root->next;
    }

    
    //if root->next is null, this means new segment is to the right of the whole list
    if(root->next == nullptr){
        Node *el = newNode(mn, mx);
        root->next = el;
        return originalRoot;
    }
    
    //we intersect the segments
    // now we need to see if we can change the max of the current node to the max of the new node
    // (combine them)
    root->high = max(root->high, mx);
    root->low = min(root->low, mn);
    
    //then delete all segments to the right of the current segment that are included in the new larger segment
    while (root->next != NULL && root->next->low < mx)
    {
        Node *temp = root->next;
        root->next = root->next->next;
        
        root->high = max(root->high, temp->high);
        delete temp;

    }

    return originalRoot;
}

int main()
{
    int n, size = 0, maxMilked = 0, maxNot = 0, lo, hi;
    
    fin >> n;
    Node *root = NULL;
    for(int i = 0; i < n; i ++)
    {
        fin >> lo >> hi;
        root = insert(root, lo, hi);
    }
    Node *elm = root;
    while(elm != nullptr){
        maxMilked = max(maxMilked, (elm->high - elm->low));
        if(elm->next != nullptr)
            maxNot = max(maxNot, (elm->next->low - elm->high));
        elm = elm->next;
    }
    fout << maxMilked << " " << maxNot << "\n";
}
/*
Executing...
Test 1: TEST OK [0.004 secs, 1372 KB]
Test 2: TEST OK [0.004 secs, 1364 KB]
Test 3: TEST OK [0.004 secs, 1368 KB]
Test 4: TEST OK [0.004 secs, 1404 KB]
Test 5: TEST OK [0.000 secs, 1388 KB]
Test 6: TEST OK [0.004 secs, 1384 KB]
Test 7: TEST OK [0.004 secs, 1448 KB]
Test 8: TEST OK [0.007 secs, 1372 KB]
 */
