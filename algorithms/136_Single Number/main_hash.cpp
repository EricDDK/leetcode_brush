//Given a non - empty array of integers, every element appears twice except for one.Find that single one.
//
//Note:
//
//Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?

#include "iostream"
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
	int singleNumber(vector<int>& nums) {
		int result = 0;
		unordered_map<int,int> map;
		for (int num :nums)
		{
			if (!map.count(num))
			{
				map[num] = 0;
			}
			else
			{
				map.erase(num);
			}
		}
		return map.begin()->first;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input = {4,1,2,1,2};
	auto result = solution->singleNumber(input);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
