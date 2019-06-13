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

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
		for (int i = 1; i <= word.size(); i++)
		{
			prefixSet.insert(prefixSet.begin(), word.substr(0, i));
		}
		set.insert(set.begin(), word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
		return set.count(word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		return prefixSet.count(prefix);
    }

	void clear() {
		set.clear();
		prefixSet.clear();
	}

private:
	unordered_set<string> set;
	unordered_set<string> prefixSet;
};

int main() {
	Trie *trie = new Trie();
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