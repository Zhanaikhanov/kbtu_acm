#include <iostream>
using namespace std;
int a[100000];
int b[100000];
int c[100000];

int curb = 0;
int cur = 0;
int size = 0;
int main()
{
	int n, m ,k;
	cin>>n>>m>>k;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		
		cin>>a[i]; 
	}
	size = n-1;

	for (int i = 0; i < n-1; ++i)
	{
		a[i] = a[i]-a[i+1];
	}

	for (int i = 0; i < n-1; ++i)
	{
		/* code */
		b[i] = a[i];
		cout<<b[i]<<" ";
	}
	cout<<" "<<size<<endl;
	int oper = 1;
	bool sta = true;
	while(size>0)
	{
			// for (int i = 0; i < n-1; ++i)
			// {
			// 	 code 
			// 	cout<<b[i]<<"|";
			// }
			// cout<<endl;
			for (int i = 0; i < size-1; ++i)
			{
				/* code */
				if (sta)
				{
					a[i] = a[i] + a[i+1] ;
				}
				else
					a[i] = a[i] + a[i+1] - b[i+1];

				b[i] = a[i];
				cout<<b[i]<<" ";
			
			}
			if (sta) sta = false;
			if (oper > 1)
				oper = 0;
			else
				oper++;
			cout<<endl;


		
	

		size--;
	}
}