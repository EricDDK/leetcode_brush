//We are playing the Guess Game.The game is as follows :
//
//I pick a number from 1 to n.You have to guess which number I picked.
//
//Every time you guess wrong, I'll tell you whether the number is higher or lower.
//
//You call a pre - defined API guess(int num) which returns 3 possible results(-1, 1, or 0) :

#include<sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
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
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> m;
		for (char c : magazine)
		{
			++m[c];
		}
		for (char c : ransomNote) 
		{
			if (--m[c] < 0) return false;
		}
		return true;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->canConstruct("fffbfg", "effjfggbffjdgbjjhhdegh");
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}