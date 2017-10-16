#include <iostream>
#include <cmath>
using namespace std;
int st1[100000];
int st2[100000];
int st3[100000];
int last1=0;
int last2=0;
int last3=0;




int main()
{
	int a,b,c;
	int s1[100000];
	int s2[100000];
	int s3[100000];
	int l1,l2,l3;
	l1=0;
	l2=0;
	l3=0;
	int d = 0;
	int sum=0;
	cin>>a>>b>>c;


	for (int i = 0; i < a; ++i)
	{
		/* code */
		cin>>d;
		
		st1[last1++] = d;
	}


	for (int i = 0; i < b; ++i)
	{
		/* code */
		cin>>d;
		st2[last2++] = d;
	}

	for (int i = 0; i < c; ++i)
	{
		/* code */
		cin>>d;

		st3[last3++] = d;
	}

//12123123

	for (int i = 0; i < a; ++i)
	{
		/* code */
		sum += st1[--last1];
		s1[l1++] = sum;
	}
	sum=0;

	for (int i = 0; i < b; ++i)
	{
		/* code */
		sum += st2[--last2];
		s2[l2++] = sum;
	}
	sum=0;

	for (int i = 0; i < c; ++i)
	{
		/* code */
		sum += st3[--last3];
		s3[l3++] = sum;
	}
	sum=0;
//123123

	l1--;
	l2--;
	l3--;
	bool ans=true;
	for (int i = 0; i < a; ++i)
	{
		int first = s1[l1-i];

		while( first < s2[l2] ){
			l2--;
		}
	
		while( first < s3[l3] ){
			l3--;
		}
		if (first == s2[l2] and first == s3[l3])
		{

			cout<<first<<endl;
			ans = false;
			break;
		}
	}



	if (ans) cout<<0<<endl;


}

