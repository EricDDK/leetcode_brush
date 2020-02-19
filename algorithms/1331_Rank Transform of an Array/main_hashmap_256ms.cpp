//Given an array of integers arr, replace each element with its rank.
//
//The rank represents how large the element is.The rank has the following rules :
//
//Rank is an integer starting from 1.
//The larger the element, the larger the rank.If two elements are equal, their rank must be the same.
//Rank should be as small as possible.

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
	vector<int> arrayRankTransform(vector<int>& arr) {
		vector<int> result(arr.size(), 0);
		map<int, int> m;
		for (int i = 0; i < arr.size(); ++i)
		{
			m[arr[i]] = 0;
		}
		int index = 1;
		for (auto it = m.begin(); it != m.end(); ++it)
		{
			m[(*it).first] = index;
			index++;
		}
		for (int i = 0; i < arr.size(); ++i)
		{
			result[i] = m[arr[i]];
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->arrayRankTransform(vector<int>{40, 10, 20, 30});
	delete solution;
	system("pause");
	return 0;
}