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

int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		if (guess(n) == 0)
			return n;
		int left = 1, right = n, mid;
		while (left < right)
		{
			mid = left + (right - left) / 2;
			int result = guess(mid);
			if (result == 0)
			{
				return mid;
			}
			else if (result == 1)
			{
				left = mid;
			}
			else
			{
				right = mid;
			}
		}
		return left;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->guessNumber(5);
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}