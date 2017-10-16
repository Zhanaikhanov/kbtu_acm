#include <iostream>
#include <map>
#include <vector>

using namespace std;
struct Node
{
	int val;
	int size;

	std::map<int, Node*> child;

	Node(int y)
	{
		val = y;
		size = 1;
	}


};

class graph
{
public:
	std::map<int, Node*> gra;


	graph()
	{

	}
	~graph()
	{

	}


	void push(int x)
	{
		Node* tmp = new Node(x);
		gra[x] = tmp;
	}


	void connect(int x, int y)
	{
		Node* x_el = gra[x];
		Node* y_el = gra[y];

		cout<<x<<"-"<<y<<endl;
		x_el->size+=y_el->size;
		x_el->child[y] = y_el;
		y_el->child[x] = x_el;
		update(x);

	}


	void update(int x)
	{
		Node* x_el = gra[x];

		if (x_el->child.size() == 1)
			return;
		for (std::map<int, Node*>::iterator it = x_el->child.begin(); it != x_el->child.end(); ++it)
		{
				Node* tmp1 = it->second;
				tmp1->size = x_el->size;
				update(tmp1->val);			
		}
	}


	
};
graph gr;

int main()
{
	int n;
	
	cin>>n;
	for (int i = 0; i < n; ++i)
		{
			/* code */
			int x;
			cin>>x;
			gr.push(x);
		}	

	cin>>n;
	for (int i = 0; i < n; ++i)
		{
			/* code */
			int x,y;
			cin>>x>>y;
			gr.connect(x,y);
		}	



}