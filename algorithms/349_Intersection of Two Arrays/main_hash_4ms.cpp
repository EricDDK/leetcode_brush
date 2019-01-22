//Given two arrays, write a function to compute their intersection.

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
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> map;
		vector<int> result = {};
		for (auto num1 : nums1)
		{
			map[num1] = 1;
		}
		for (auto num : nums2)
		{
			if (map.count(num))
			{
				map[num]++;
				if (map[num] == 2)
				{
					result.push_back(num);
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input1 = { 4, 9, 5 };
	vector<int> input2 = { 9, 4, 9, 8, 4 };
	auto result = solution->intersection(input1, input2);
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}