#include <iostream>
#include <cmath>
using namespace std;
double fun(int x)
{
	return (x*x*x+cos(x)) - (x*x*x+cos(x))%0.2;
}

int main()
{
	int m=6;
	int sum=0;
	int matrix[m][m];
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>matrix[i][j];
		}
	}
	int iu=0;
	for (int i = 0; i < m; ++i)
	{
		/* code */
		if (matrix[i][m-i-1]<5) iu++;
	}

	cout<<iu;
}