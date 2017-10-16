#include <iostream>
#include <map>
#include <vector>
//#include <string>

struct node
{
	char ch;
	std::map<char, node*> children;
};

class Trie
{
public:
	Trie(){ head.ch = -1 ;};
	~Trie();
	void build_trie(string[] words, int length);
	void insert(string word);
	
	void search(string word, bool &result);
	void print_tree(string &answer);

protected:
	node head;
	std::vector<node*> children; 

};

Trie::~Trie()
{
	for (int i = 0; i < children.size(); ++i)
	{
		/* code */
		delete children[i];
	}
}

void Trie::build_trie(string words[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		/* code */
		insert(words[i]);
	}
}

void Trie::insert(string word)
{
	std::map<char, node*> *current_tree = &head.children;
	std::map<char, node*>::iterator it;

	for (int i = 0; i < word.length(); ++i)
	{
		/* code */
		char ch = word[i];
		if (it=current_tree->find(ch)!=current_tree->end())
		{
			current_tree = &it->second->children;
			continue;
		}

		if (it == current_tree->end())
		{
			node new_node = new node();
			new_node->ch = ch;
			(*current_tree)[ch] = new_node;
			current_tree = &new_node->children;
		
			children.push_back(new_node);
		}
	}
}

void Trie::search(string word , bool &result)
{	
	std::map<char, node*> current_tree = head.children;
	std::map<char, node*>::iterator it;

	for (int i = 0; i < word.length(); ++i)
	{
		/* code */
		if (it=current_tree->find(word[i]) == current_tree.end())
		{
			result false;
			return;
		}
		current_tree = it->second->children;
	}

	result true;
	return;
}

void Trie::print_tree(std::map<char, node*> tree)
{
	if (tree.empty())
		return;

	for (std::map<char, node*>::iterator it = tree.begin(); it != tree.end(); ++it)
	{
		cout<< it->first << endl;
		print_tree(it->second->children);
	}
}

void Trie::print()
{
	std::map<char, node*> current_tree = head.children;
	print_tree(current_tree);
}

int main()
{
	string words[] = {"foo", "bar", "baz", "barz"};
	Trie trie;
	trie.build_trie(words, 4);
	cout<<"all nodes"<<endl;
	trie.print();
	cout<<"all nodes"<<endl;

}