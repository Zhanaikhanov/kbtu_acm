#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	set<int> msset;

	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		int com;
		cin>>com;
		if (com == 1)
		{
			int data;
			cin>>data;
			msset.insert(data);
		}
		if (com == 2)
		{
			int data;
			cin>>data;
			msset.erase(data);			
		}
		if (com == 3)
		{
			cout<<*msset.begin()<<endl;
		}

	}


}w