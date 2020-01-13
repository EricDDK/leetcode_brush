//Suppose you have a random list of people standing in a queue.Each person is described by a pair of integers(h, k), 
//where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h.
//Write an algorithm to reconstruct the queue.

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
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) 
		{
			return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
		});
		vector<vector<int>> result;
		for (auto a : people)
		{
			result.insert(result.begin() + a[1], a);
		}
		return result;
	}

	unordered_map<int, vector<int>> forward;
	unordered_map<int, vector<int>> reverse;

};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->reconstructQueue(vector<vector<int>>{
		vector<int>{7, 0},
		vector<int>{4, 4},
		vector<int>{7, 1},
		vector<int>{5, 0},
		vector<int>{6, 1},
		vector<int>{5, 2},
	});
	if (result != vector<vector<int>>{
		vector<int>{5, 0},
		vector<int>{7, 0},
		vector<int>{5, 2},
		vector<int>{6, 1},
		vector<int>{4, 4},
		vector<int>{7, 1},
	})
		throw;
	delete solution;
	system("pause");
	return 0;
}