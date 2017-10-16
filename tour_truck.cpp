#include <iostream>
using namespace std;
struct Node
{
    int val;
    int dist;
    int count;
    Node *next;
    Node(int v, int d)
    {
        this->val = v-d;
        this->dist = d;
        this->count = 0;
    }
};

class tour_truck
{
public:
    Node *begin;
    Node *root;
    Node *cur;
    Node *last;
    tour_truck()
    {
        last = NULL;
        cur = NULL;
        root = NULL;
    }


    void push(int value, int dis)
    {
        
        cur = new Node(value, dis);
        if (last == NULL and root ==NULL)
        {
            last = cur;
            root = cur;
            begin = cur;
        }
        else if (root == NULL)
        {
            root = cur;
            last->next = cur;
        }
        else if (root != NULL)
        {
            last->next = cur;
            last = cur;
            if (cur->val<0)
            {
                root->next = cur;
                root->count+=1;
                root=NULL;
            }
            else if (cur->val>=0)
            {
                root->val += cur->val;
                root->count+=1;
                root->next = cur;
            }
        }
    }
    
};


tour_truck tour;

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        /* code */
        int cap, dist;
        cin>>cap>>dist;
        tour.push(cap, dist);
    }
    cout<<tour.begin->val;
}
