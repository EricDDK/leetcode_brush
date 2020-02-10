//A gene string can be represented by an 8 - character long string, with choices from "A", "C", "G", "T".
//
//Suppose we need to investigate about a mutation(mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.
//
//For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
//
//Also, there is a given gene "bank", which records all the valid gene mutations.A gene must be in the bank to make it a valid gene string.
//
//Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end".If there is no such a mutation, return -1.
//
//Note:
//
//Starting point is assumed to be valid, so it might not be included in the bank.
//If multiple mutations are needed, all mutations during in the sequence must be valid.
//You may assume start and end string is not the same.

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

class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		if (bank.empty()) 
			return -1;
		vector<char> gens{ 'A','C','G','T' };
		unordered_set<string> set(bank.begin(), bank.end());
		queue<string> q({ start });
		int result = 0;
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; ++i)
			{
				string t = q.front();
				q.pop();
				if (t == end)
					return result;
				set.erase(t);
				string pattern;
				for (int j = 0; j < t.size(); ++j)
				{
					pattern = t;
					for (auto& g : gens)
					{
						pattern[j] = g;
						if (set.count(pattern))
							q.push(pattern);
					}
				}
			}
			++result;
		}
		return -1;
	}

};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->minMutation("AACCGGTT", "AACCGGTA", vector<string>{"AACCGGTA"});
	if (result != 1)
		throw;
	result = solution->minMutation("AACCGGTT", "AAACGGTA", vector<string>{"AACCGGTA", "AACCGCTA", "AAACGGTA"});
	if (result != 2)
		throw;
	result = solution->minMutation("AAAAACCC", "AACCCCCC", vector<string>{"AAAACCCC", "AAACCCCC", "AACCCCCC"});
	if (result != 3)
		throw;
	result = solution->minMutation("AACCTTGG", "AATTCCGG", vector<string>{"AATTCCGG", "AACCTGGG", "AACCCCGG", "AACCTACC"});
	if (result != -1)
		throw;
	delete solution;
	system("pause");
	return 0;
}