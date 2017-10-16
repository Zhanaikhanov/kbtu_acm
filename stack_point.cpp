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

		else if (head != NULL)
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
};

int main()
{
	stack_point a1,a2,a3;
			
}
