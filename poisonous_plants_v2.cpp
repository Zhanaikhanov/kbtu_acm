#include <vector>
#include <iostream>
using namespace std;
int main()
{
	vector<int> v;

	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		int y;
		cin>>y;
		v.push_back(y);
	}
	
	int del=0;
	int cnt=0;
	int size = v.size();
	while(del>0)
	{
		cnt++;
		int l = *v.begin();
		int r = *v.end();
		if (l<=r)
		{		
			v.push_back(v.begin());
			v.erase(v.begin());
			del++;
		}

		if (cnt==(size-del))
		{
			ans++;
			del=0;
			cnt=0;
		}

	}
}