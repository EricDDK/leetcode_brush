//Given a m * n matrix mat of ones(representing soldiers) and zeros(representing civilians), return the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.
//
//A row i is weaker than row j, if the number of soldiers in row i is less than the number of soldiers in row j, or they have the same number of soldiers but i is less than j.Soldiers are always stand in the frontier of a row, that is, always ones may appear first and then zeros.

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
	int minSetSize(vector<int>& arr) {
		int n = arr.size();
		unordered_map<int, int> m;
		for (auto& a : arr)
		{
			m[a]++;
		}
		map<int, int> m1;
		for (auto& s : m)
		{
			m1[s.second]++;
		}
		int result = 0;
		int tmp = 0;
		auto it = m1.rbegin();
		while (it != m1.rend())
		{
			while (tmp < n / 2 && (*it).second > 0)
			{
				tmp += (*it).first;
				result++;
				(*it).second--;
			}
			it++;
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->minSetSize(vector<int>{3, 3, 3, 3, 5, 5, 5, 2, 2, 7});
	if (result != 2)
		throw;
	result = solution->minSetSize(vector<int>{1,9});
	if (result != 1)
		throw;
	result = solution->minSetSize(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
	if (result != 5)
		throw;
	delete solution;
	system("pause");
	return 0;
}