#include <iostream>
using namespace std;




int main()
{
	

	int n;
	int cur=0;
	cin>>n;
	int arr[n];
	long long total[n];
	long long area;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>arr[i];
	}



	for (int i = 0; i < n; ++i)
	{
		/* code */
	

		area = 0;
		area++;
		if (i == 0)
		{
			//right
			int r=i+1;
			while (arr[i] <= arr[r] && r!=n)
			{
				r++;
				area++;
			}		
		}
		else if (i == n-1)
		{
			//left
			int l=i-1;
			while (arr[i] <= arr[l] && l!=-1)
			{
				l--;
				area++;
			}
		}
		else 
		{

			int r=i+1;
			while (arr[i] <= arr[r] && r!=n)
			{
				r++;
				area++;
			}

			int l=i-1;
			while (arr[i] <= arr[l] && l!=-1)
			{
				l--;
				area++;
			}

		}

		total[cur++] = area*arr[i];
	}


	long long ans=0;
	for (int i = 0; i < cur; ++i)
	{
		/* code */

		if (total[i]>ans)
			ans = total[i];
	}

	cout<<ans<<endl;
	return 0;
}



