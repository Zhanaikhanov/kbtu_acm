#include <iostream>
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
		this->size++;
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

	void pop()
	{

		if (head == NULL)
		{
			return;
		}

		if (head == begin)
		{
			int data = head->val;
			head = NULL;
			begin = NULL;
			size=0;
		}

		else if (head != NULL)
		{
			/* code */
			head = head->prev;
			head->next = NULL;
			size--;
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
};

bool isOpen(char x)
{
	char opens[3];
	opens[0] = '{';
	opens[1] = '[';
	opens[2] = '(';
	for (int i = 0; i < 3; ++i)
	{
		/* code */
		if (x == opens[i])
			return true;
	}

	return false;
}

bool closes(char x, char y)
{
	if (x == '{' & y == '}')
		return true;
	if (x == '[' & y == ']')
		return true;
	if (x == '(' & y == ')')
		return true;

	return false;
}

int main()
{
	stack_point a; // top, pop ,push, clear;

	int n;
	cin>>n;
	string o[n];
	string x;
	bool ans=true;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>o[i];
	}


	for (int i = 0; i < n; ++i)
	{	
		x = o[i];
		/* code */
		a.clear();
		for (int j = 0; j < x.length(); ++j)
			{
				/* code */
				if (closes(a.top(), x[j]))
				{
					a.pop();
				}
				else
					a.push(x[j]);
			}	
	}
		if (ans)
		{
			if (a.size==0) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		} 
		ans=true;

			
}
