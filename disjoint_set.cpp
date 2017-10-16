#include <iostream>
#include <vector>

using namespace std;
int parents[10000];
int rank[10000];
int size[10000];
std::vector<int> v;
void make_node(int x)
{
	parents[x] = x;
	rank[x] = 0;
	size[x] = 1;
	v.push_back(x);
}

int find_parent(int x)
{
	if (parents[x] == x)
		return x;
	else
		return find_parent(parents[x]);
}

void connect(int x, int y)
{
	x = find_parent(x);
	y = find_parent(y);


	if (rank[x] > rank[y])
		{
		parents[y] = x;
		size[x] += size[y];
		}
	else 
	{
		parents[x] = y;
		size[y] += size[x];

		if(rank[x] == rank[y])
			rank[y] = rank[y]+1;
	}

}

int main()
{


	while (1)
	{
		string in;
		cin>>in;

		if (in == "FP")
		{
			int t;
			cin>>t;
			cout<<"parent of "<<t<<" is :";
			cout<<find_parent(t)<<endl;
		}

		if (in == "CN")
		{
			int t,y;
			cin>>t>>y;
			cout<<"connect "<<t<<" with "<<y<<endl;
			connect(t,y);
		}

		if (in == "MK")
		{
			int y;
			cin>>y;
			make_node(y);
		}

		if (in == "EXIT")
		{
			cout<<"BYE"<<endl;
			for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
			{
				cout<<size[*i]<<" ";
			}
			cout<<endl;
			break;
		}
	}

}


