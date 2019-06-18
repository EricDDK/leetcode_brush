//Design a data structure that supports the following two operations :
//
//void addWord(word)
//bool search(word)
//search(word) can search a literal word or a regular expression string containing only letters a - z or ..A.means it can represent any one letter.
//
//Example :
//
//	addWord("bad")
//	addWord("dad")
//	addWord("mad")
//	search("pad") -> false
//	search("bad") -> true
//	search(".ad") -> true
//	search("b..") -> true

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include "windows.h"
#include <algorithm>
#include <stack>
#include <string>
#include <queue>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

class TrieNode
{
public:
	TrieNode* child[26];
	bool isEnd;
	TrieNode()
		:isEnd(false)
	{
		for (auto& a : child)
			a = NULL;
	}
	~TrieNode()
	{
		for (int i = 0; i < 26; i++)
		{
			delete child[i];
		}
	}
};

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new TrieNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode *tmp = root;
		for (auto& c : word)
		{
			int t = c - 'a';
			if (!tmp->child[t])
				tmp->child[t] = new TrieNode;
			tmp = tmp->child[t];
		}
		tmp->isEnd = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return searchDFS(word, root, 0);
	}

	bool searchDFS(const string& word, TrieNode *p, int index) {
		if (word.size() == index)
			return p->isEnd;
		if (word[index] == '.')
		{
			for (auto& c : p->child)
			{
				if (c && searchDFS(word, c, index + 1))
					return true;
			}
			return false;
		}
		else
		{
			return (p->child[word[index] - 'a'] && searchDFS(word, p->child[word[index] - 'a'], index + 1));
		}
	}

private:
	TrieNode *root;

};


int main() {
	WordDictionary w;
	w.addWord("bad");
	w.addWord("dad");
	w.addWord("mad");
	if (w.search("pad"))
		throw;
	if (!w.search("bad"))
		throw;
	if (!w.search(".ad"))
		throw;
	if (!w.search("b.."))
		throw;
#ifdef _MSC_VER
	_CrtDumpMemoryLeaks();
	system("pause");
#else
	
#endif
	return 0;
}