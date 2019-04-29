//Given two words(beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//
//Only one letter can be changed at a time.
//Each transformed word must exist in the word list.Note that beginWord is not a transformed word.
//Note:
//
//Return 0 if there is no such transformation sequence.
//All words have the same length.
//All words contain only lowercase alphabetic characters.
//You may assume no duplicates in the word list.
//You may assume beginWord and endWord are non - empty and are not the same.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> hset(wordList.begin(), wordList.end());
		if (!hset.count(endWord))
			return 0;
		queue<string> q({beginWord});
		int result = 1;
		while (!q.empty())
		{
			int qSize = q.size();
			for (int i = 0; i < qSize; ++i)
			{
				string word = q.front();
				if (word == endWord)
					return result;
				hset.erase(word);
				string pattern;
				q.pop();
				for (int j = 0; j < word.size(); ++j)
				{
					pattern = word;
					for (int k = 0; k < 26; ++k)
					{
						pattern[j] = 'a' + k;
						if (hset.count(pattern))
							q.push(pattern);
					}
				}
			}
			++result;
		}
		return 0;
	}
};

int main()
{
	Solution* solution = new Solution;
	/*vector<string> input = { "hot","dot","dog","lot","log","cog" };
	auto result = solution->ladderLength("hit", "cog", input);*/
	vector<string> input = { "hot","dog"};
	auto result = solution->ladderLength("hot", "dog", input);
	delete(solution);
	system("pause");
	return 0;
}