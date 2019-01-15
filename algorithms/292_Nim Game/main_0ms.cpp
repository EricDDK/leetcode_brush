//You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones.The one who removes the last stone will be the winner.You will take the first turn to remove the stones.
//
//Both of you are very clever and have optimal strategies for the game.Write a function to determine whether you can win the game given the number of stones in the heap.

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
	bool canWinNim(int n) {
		return n % 4;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->canWinNim(4);
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}