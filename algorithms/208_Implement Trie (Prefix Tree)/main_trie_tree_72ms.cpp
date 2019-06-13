//Implement a trie with insert, search, and startsWith methods.

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

using namespace std;

class TrieNode {
public:
	TrieNode* child[26];
	bool isEnd;
	TrieNode()
		:isEnd(false)
	{
		for (auto& a : child)
			a = NULL;
	}
};

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode;
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* tmp = root;
		for (auto& s : word)
		{
			int value = s - 'a';
			if (!tmp->child[value])
				tmp->child[value] = new TrieNode;
			tmp = tmp->child[value];
		}
		tmp->isEnd = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* tmp = root;
		for (auto& s : word)
		{
			int value = s - 'a';
			if (!tmp->child[value])
				return false;
			tmp = tmp->child[value];
		}
		return tmp->isEnd;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode* tmp = root;
		for (auto& s : prefix)
		{
			int value = s - 'a';
			if (!tmp->child[value])
				return false;
			tmp = tmp->child[value];
		}
		return true;
	}

	void clear() {
		delete root;
	}

private:
	TrieNode* root;

};

int main() {
	Trie* trie = new Trie();
	trie->insert("apple");
	if (!trie->search("apple"))
		throw;
	if (trie->search("app"))
		throw;
	if (!trie->startsWith("app"))
		throw;
	trie->insert("app");
	if (!trie->search("app"))
		throw;

	trie->clear();
	trie->insert("a");
	if (!trie->search("a"))
		throw;
	if (!trie->startsWith("a"))
		throw;
	delete trie;
	system("pause");
	return 0;
}