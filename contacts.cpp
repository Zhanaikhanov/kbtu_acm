#include <iostream>
using namespace std;
struct node
{
	char val;
	int to[26];
	bool isEnd;
	node(char t)
	{
		val = t;
	}
};
node a[10000];
int sz=1;


void add(string s)
{
	int cur=0;
	for (int i = 0; i < s.length(); ++i)
	{
		/* code */
		int v = s[i] - 'a';
		if (a[cur].to[i]!=0)
		{
			cur = a[cur].to[v];
		}
		else
		{
			a[cur].to[v] = sz;
			cur=sz;
			sz++;
		}

	}
	a[cur].isEnd = true;
}


void find(string s)
{
	int cur=0;
	string ans="";
	for (int i = 0; i < s.length(); ++i)
	{
		/* code */
		int v = s[i] - 'a';
		if (a[cur].to[i]!=0)
		{
			cur = a[cur].to[v];
		}
		else
		{
			return;
		}

	}

	Rec(cur, ans);


}


void Rec(int cur, string s)
{
	if (a[cur].isEnd)
	{
		cout<<s<<endl;
		return;
	}
	for (int i = 0; i < 26; ++i)
	{
		/* code */
		if (a[cur].to[i]!=0)
			Rec(a[cur].to[i], (s+(i+'a')));
	}

}

int main()
{
	add("beka");
}
