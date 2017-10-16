#include <iostream>
#include <cmath>
int min(int a, int b, int c)
{
	if (a>=b && b>=c)
	{
		return c;
	}
	if (a>=c && c>=b)
	{
		return b;
	}
	if (b>=a && a>=c)
	{
		return c;
	}
	if (b>=c && c>=a)
	{
		return a;
	}
	if (c>=a && a>=b)
	{
		return b;
	}
	if (c>=b && b>=a)
	{
		return a;
	}	
}
int min(int a, int b)
{
	if (a>=b)
	{
		return b;
	}
	else 
		return a;

}
using namespace std;
int main()
{
	int n;
	int a,b,c;
	int res = 0;
	cin>>n;
	cin>>a>>b>>c;
	int mini = min(a,b,c);	
	
	bool started = true;

	while(n>1)
	{
		if (c == mini && started)
		{
			n--;
			res+=min(a,b);
			started = false;
			continue;
		}

		n--;

		res+=mini;

	}

	cout<<res<<endl;

}