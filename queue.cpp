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

class queue_p
{
public:
	Node *head;
	Node *begin;
	int size;
	queue_p()
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

		if (begin == NULL)
		{
			return -1;
		}

		if (head == begin)
		{
			int data = begin->val;
			head = NULL;
			begin = NULL;
			size=0;
			return data;
		}

		else if (begin != NULL)
		{
			/* code */
			int data = begin->val;
			begin = begin->next;
			begin->prev = NULL;
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

	int back()
	{
		if (begin==NULL)
			return -1;
		return begin->val;
	}
	
	void clear()
	{
		head = NULL;
		begin = NULL;
	}
};

int main()
{
	queue_p a1,a2,a3;
			
}