#include <bits/stdc++.h>

using namespace std;


struct Node
{
    int val;
    Node * prev;
    Node * next;
    Node (int v)
    {
        this->val = v;
    }

};

class stack_point
{
public:
    Node *head;
    Node *begin;
    int size;
    stack_point()
    {
        size=0;
        head = NULL;
        begin = NULL;
    }

    void push(int v)
    {
        Node *new_n = new Node(v);
        size++;
        if (head == NULL)
        {
            begin = new_n;
            head = new_n;
            head->next = NULL;
            head->prev = NULL;
        }
        if (head != NULL)
        {
            /* code */
            head->next = new_n;
            new_n->prev = head;
            head = new_n;
        }
    }

    void push_back(int v)
    {
        Node *new_n = new Node(v);
        size++;
        if (begin == NULL)
        {
            begin = new_n;
            head = new_n;
            begin->next = NULL;
            begin->prev = NULL;
        }
        if (begin != NULL)
        {
            /* code */
            begin->prev = new_n;
            new_n->next = begin;
            begin = new_n;
        }
    }


    int pop()
    {

        if (head == NULL)
        {
            return -1;
        }

        if (head == begin)
        {
            int data = head->val;
            head = NULL;
            begin = NULL;
            size=0;
            return data;
        }

        else
        {
            /* code */
            int data = head->val;
            head = head->prev;
            head->next = NULL;
            size--;
            return data;
        }
    }

    int top()
    {
        if (head==NULL)
            return -1;
        return head->val;
    }

    
    void clear()
    {
        head = NULL;
        begin = NULL;
    }

    void get()
    {
        Node *cur = begin;
        for (int i=0;i<this->size;i++)
        {
            cout<<cur->val<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
};







int main(){
    int left ;
    int right ;
    int count = 0;
    int sum = 0;
    int n;
    int m;
    int x;
    stack_point a1,a2;
    stack_point b1,b2;
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        cin >> n >> m >> x;
    
        a1.clear();
        a2.clear();
        for (int i = 0; i < n; ++i)
        {
            /* code */
            int y;
            cin>>y;
            a1.push_back(y);
        }


        for (int i = 0; i < m; ++i)
        {
            /* code */
            int y;
            cin>>y;
            a2.push_back(y);
        }

//111111111111111111

        sum=0;
        b1.clear();
        int y1, y2;
        for (int i = 0; i < n; ++i)
        {
            /* code */
            y1=a1.pop();
            sum=sum+y1;
            b1.push_back(sum);

        }
        sum=0;
        for (int i = 0; i < m; ++i)
        {
            /* code */
            y2=a2.pop();
            sum+=y2;
            b2.push_back(sum);
        }

        sum=0;
        //get

        count=0;

        while (sum<x)
        {
            if (b1.top() < b2.top())
            {
                sum+=b1.pop();
            }
            else if (b1.top() > b2.top())
            {
                sum+=b2.pop();
            }


            else if (b1.top() == b2.top())
            {
                sum+=b1.pop();
            }
            count++;            
               


        }

        cout<<count<<endl;


// 1
// 5 4 10
// 4 2 4 6 1
// 2 1 8 5

    }
    return 0;
}