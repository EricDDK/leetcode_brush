//Given an array with n objects colored red, white or blue, sort them in - place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//Note: You are not suppose to use the library's sort function for this problem.

#include <sstream>
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
	void sortColors(vector<int>& nums) {
		sort(nums.begin(), nums.end());
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = {2,0,2,1,1,0};
	/*auto result = */solution->sortColors(input);
	//cout << result << endlsearchMatrix
	delete(solution);
	system("pause");
	return 0;
}