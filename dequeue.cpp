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

class dequeue_p
{
public:
	Node *head;
	Node *begin;
	int size;
	dequeue_p()
	{
		size=0;
		head = NULL;
		begin = NULL;
	}

	void push_back(int v)
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
	void push_front(int v)
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



	int pop_back()
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
	int pop_front()
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
	dequeue_p a1,a2,a3;
			
}