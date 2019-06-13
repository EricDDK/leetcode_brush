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
		map.insert(map.begin(), { word, false });
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
		return map.count(word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		for (auto &m : map)
		{
			if (m.first.size() >= prefix.size() && m.first.substr(0, prefix.size()) == prefix)
			{
				return true;
			}
		}
		return false;
    }

	void clear() {
		map.clear();
	}

private:
	unordered_map<string, bool> map;

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