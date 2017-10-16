#include <iostream>
#include <vector>

using namespace std;
int parents[1000000];
int ranking[1000000];
int size[1000000];
std::vector<int> v;
void make_node(int x)
{
	if (parents[x]==0)
	{	
		parents[x] = x;
		ranking[x] = 0;
		size[x] = 1;
		v.push_back(x);
	}
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


	if (ranking[x] > ranking[y])
		{
		parents[y] = x;
		size[x] += size[y];
		}
	else 
	{
		parents[x] = y;
		size[y] += size[x];

		if(ranking[x] == ranking[y])
			ranking[y] = ranking[y]+1;
	}

}

int main()
{

	int n;
	cin>>n;
	for (int i = 1; i <= n + n; ++ i)
		parents[i] = i;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		int x,y;
		cin>>x>>y;
		make_node(x);
		make_node(y);
		connect(x, y);

	}

	int max = 2;

	for (int i = 1; i <= n + n; ++ i)
	{

		if (size[find_parent(*i)]>max)
		{
			max = size[find_parent(*i)];
		}
	}

	int min = max;
	for (int i = 1; i <= n + n; ++ i)
	{
		if (size[find_parent(*i)]<min and ranking[*i]>0)
		{
			min = size[find_parent(*i)];
		}
	}
	
	cout<<min<<" "<<max<<endl;
}


