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
        l.push_back(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
    	for (auto iter = l.begin(); iter != l.end(); ++iter)
    	{
    		if (*iter == word)
    		{
    			l.erase(iter);
        		return true;
    		}
    	}
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        for (auto &str : l)
        {
        	if (str.size() >= prefix.size())
        	{
        		bool b = true;
        		for (int i = 0; i < prefix.size(); ++i)
	        	{
	        		if (prefix[i] != str[i])
	        		{
	        			b = false;
	        			break;
	        		}
	        	}
	        	if (b)
	        		return true;
        	}
        }
        return false;
    }

private:
	list<string> l;
	
};

int main() {
	Trie *trie = new Trie();
	trie.insert("apple");
	if (!trie.search("apple"))
		throw;
	if (trie.search("app"))
		throw;
	if (!trie.startsWith("app"))
		throw;
	trie.insert("app");   
	if (!trie.search("app"))
		throw;
	delete trie;
	system("pause");
	return 0;
}