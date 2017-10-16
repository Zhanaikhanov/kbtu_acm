#include <iostream>
using namespace std;


struct Node
{
	char val;
	Node * prev;
	Node * next;
	Node (char v)
	{
		prev=NULL;
		next=NULL;
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

	void push(char v)
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

	void pop()
	{

		if (head == NULL)
		{
			return;
		}

		if (head == begin)
		{
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


	
	void clear()
	{
		head = NULL;
		begin = NULL;
		size=0;
	}


	string get()
	{
		string out="";
		
		if (begin!=NULL){
			Node *cur_word=begin;
			out+=cur_word->val;

			while(cur_word!=head)
			{
				cur_word = cur_word->next;
				out+=cur_word->val;
			}
		}

		return out;
	}


	char get_at_point(int pos)
	{
		pos--;
		Node *cur_word=begin;
		if (pos<size){
			for (int i = 0; i < pos; ++i)
			{
				/* code */
				cur_word = cur_word->next;
			}
			return cur_word->val;
		}

		return ' ';

	}




};
//push
//top
//clear
//pop
//stack_point a1;

string events[1000500];
int main()
{
	int n;
	int t;
	int ev=0;
	int last_del=0;
	int print_idx=0;
	string text="";
	string toto="";
	string output="";
	string event_string = "";
	stack_point line;

	events[ev++] = "";
	events[ev++] = "";
	events[ev++] = "";
	events[ev++] = "";
	events[ev++] = "";
	cin>>n;

	for (int j = 0; j < n; ++j)
	{
		/* code */
		cin>>t;

		if (t==1)
		{
			cin>>text;

			for (int i = 0; i < text.length(); ++i)
			{
				/* code */
				line.push(text[i]);
			}

		}
		else if (t==2)
		{
			cin>>last_del;
			if (last_del<=line.size)
			{
				for (int i = 0; i < last_del; ++i)
				{
					/* code */
					line.pop();
				}
			}
		}
		else if (t==3)
		{	
			cin>>print_idx;
			if (print_idx<=line.size)
				output+=line.get_at_point(print_idx);
		}
		if (t==4)
		{

			ev--;
			event_string = events[ev-1];
			
			line.clear();
			for (int i = 0; i < event_string.length(); ++i)
			{
				/* code */
				line.push(event_string[i]);
			}
			// cout<<line.get()<<"---"<<endl;

		}else if (events[ev-1] != line.get())
			events[ev++] = line.get();

	}



	for (int i = 0; i < output.length(); ++i)
	{
		/* code */
		cout<<output[i]<<endl;

	}





	// cout<<"====="<<endl;
	// for (int i = 0; i < ev; ++i)
	// {

	// 	cout<<events[i]<<endl;
	// }
	// cout<<"====="<<endl;

}