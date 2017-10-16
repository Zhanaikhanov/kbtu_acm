#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
	std::multiset<int> ms;
	int n,x;
	cin>>n>>x;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		int y;
		cin>>y;
		ms.insert(y);
	}
	int ans=0;
	while(*ms.begin()<x)
	{
		ans++;

		int f = *ms.begin();
		ms.erase(ms.begin());
		f+=*ms.begin()*2;
		ms.erase(ms.begin());


		ms.insert(f);


		if(ms.size() == 1 && *ms.begin()<x)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;


}