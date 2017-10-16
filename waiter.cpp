#include <iostream>
using namespace std;
int arr1[100500];
int arr2[100500];
int arr3[100500];
int star = 1;
void mix(int ar1[], int ar2[], int n)
{	int se=0;
	if (star){
		for (int i = star; i < n; i+=2)
		{
			/* code */
			ar2[se++] = ar1[i];
		}

		for (int i = star-1; i < n; i+=2)
		{
			/* code */
			ar2[se++] = ar1[i];
		}
	}else{
		for (int i = star; i < n; i+=2)
		{
			/* code */
			ar2[se++] = ar1[i];
		}

		for (int i = star+1; i < n; i+=2)
		{
			/* code */
			ar2[se++] = ar1[i];
		}
	}
	if (star == 0) star=1;
	else star=0;
}
//33449
//34349
//33944


int main()
{
	int n,g;
	
	cin>>n>>g;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>arr1[i];
	}



	for (int i = 0; i < g; ++i)
	{
		/* code */
		mix(arr1, arr2, n);
		for (int j = 0; j < n; ++j)
		{
			/* code */
			arr1[j] = arr2[j];
		}

		
	}

		for (int h = 0; h < n; ++h)
		{
			/* code */
			cout<<arr1[h]<<endl;
		}
	// for (int i = 1; i < n; i+=2)
	// {
	// 	/* code */
	// 	arr2[sec++] = arr1[i];
	// }

	// for (int i = 0; i < n; i+=2)
	// {
	// 	/* code */
	// 	arr2[sec++] = arr1[i];
	// }


}