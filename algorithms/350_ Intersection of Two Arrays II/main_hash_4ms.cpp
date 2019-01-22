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
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> map;
		vector<int> result = {};
		for (auto num : nums1)
		{
			if (map.count(num))
			{
				map[num]++;
			}
			else
			{
				map[num] = 1;
			}
		}
		for (auto num : nums2)
		{
			if (map.count(num))
			{
				map[num]--;
				if (map[num] >= 0)
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
	vector<int> input1 = { 1,2,2,1 };
	vector<int> input2 = { 2,2 };
	auto result = solution->intersect(input1, input2);
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}