#include <iostream>
using namespace std;

int values[100000];
int sums_plus[100000];
int sums_min[100000];

int next[100000];
int laps[100000];
int cur=0;


int main()
{
	int n;
	cin>>n;
	int sums=0;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		int cap, dista;
		cin>>cap>>dista;		
		values[i] = cap;	
		sums+=cap-dista;
		cur++;
	}


	for (int i = 0; i < n; ++i)
	{
		/* code */
		if (values[i]>=sums)
		{
			cout<<i+1<<endl;
			break;
		}
	}
}