#include <iostream>
using namespace std;
struct Node
{
	char val;
	Node *alpha[26];
	Node(char w)
	{
		this->val = w;
	}

	bool itContains(char t)
	{
		return this->alpha[t]->val == t;
	}
};


class trie
{
public:
	Node *root = NULL;
	trie()
	{
		root = new Node('#');
	}

	void push(string word)
	{
		Node *cur = root;
		for (int i = 0; i < word.length(); ++i)
		{
			Node *new_w = new Node(word[i]);
			/* code */
			if (cur->itContains(word[i]))
			{
				cur = cur->alpha[word[i]];
			}
			else
			{
				cur->alpha[word[i]] = new_w;
			}

		}
	}


	// bool have_it_prefix(string word)
	// {
	// 	Node *cur = root;
	// 	for (int i = 0; i < word.length(); ++i)
	// 	{
	// 		/* code */
	// 		if (cur== NULL)
	// 			return false;
	// 		if (cur->itContains(word[i]))
	// 		{
	// 			cur = cur->alpha[word[i]];
	// 		}
	// 		else
	// 		{
	// 			return false;	
	// 		}

	// 	}	
	// 	return true;
	// }
	
	void get()
	{
		Node *cur = root;
		cout<<cur->val;
	}
	
};



trie tt;
int main()
{

	tt.push("abcd");
	tt.get();

}