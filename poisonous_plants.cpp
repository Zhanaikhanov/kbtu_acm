#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node *next;
	Node *prev;
	Node(int h)
	{
		this->val=h;
	}
};


class linked_list
{
public:
	Node *start;
	Node *end;
	Node *this_el;
	int size;
	bool changed;
	linked_list(){
		start = NULL;
		end = NULL;
		size = 0;
		changed = false;
	}

	void push_to_end(int a)
	{
		size++;
		changed = true;
		Node *cur = new Node(a);
		if (start == NULL)
		{
			start = cur;
			end = cur;
			this_el = cur;
		}
		else
		{
			end->next = cur;
			cur->prev = end;
			end = cur;
		}
	}


	void delete_it()
	{	
		size--;
		changed = true;
		if (this_el->next != NULL)
		{
			Node *n = this_el->next;
			n->prev = this_el->prev;
			n = this_el->prev;
			n->next = this_el->next;
		}
		if (this_el->next == NULL)
		{
			Node *n = this_el->prev;
			n->next = NULL;
		}

		if (this_el->prev == NULL)
		{
			Node *n = this_el->next;
			n->prev = NULL;
		}
	}

	void to_end()
	{
		if (this_el->next != NULL)
			this_el = this_el->next;
	}
	void to_start()
	{
		if (this_el->prev != NULL)
			this_el = this_el->prev;
	}


	int get_this()
	{
		return this_el->val;
	}

	void start_from_start()
	{
		this_el = start;

	}

	void start_from_end()
	{
		this_el = end;
	}

	void reset()
	{
		changed = false;
	}
};


linked_list lists;
int main()
{
int n;
cin>>n;

for (int i = 0; i < n; ++i)
{
	/* code */
	int c;
	cin>>c;
	lists.push_to_end(c);
}


lists.changed = true;
int count = 0;
int size;
int last;
int current;
while(lists.changed){

	lists.reset();
	lists.start_from_start();
	size= lists.size-1;
	for (int i = 0; i < size; ++i)
	{
		last=lists.get_this();
		lists.to_end();
		current = lists.get_this();
		
		if (current>last)
		{
			lists.delete_it();
		}	

	}
	count++;

}
cout<<--count<<endl;

}