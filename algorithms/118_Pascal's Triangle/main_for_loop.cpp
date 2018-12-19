//Given a non - negative integer numRows, generate the first numRows of Pascal's triangle.

#include "iostream"
#include <vector>
#include <unordered_map>
#include <map>
#include <hash_set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result(numRows);
		if (numRows >= 1)
		{
			result[0] = { 1 };
		}
		if (numRows >= 2)
		{
			result[1] = { 1, 1 };
		}
		if (numRows >= 3)
		{
			for (int i = 3; i <= numRows; i++)
			{
				vector<int> v(i);
				v[0] = 1;
				v[i-1] = 1;
				for (int j = 1; j < i - 1; j++)
				{
					v[j] = result[i - 2][j - 1] + result[i - 2][j];
				}
				result[i-1] = v;
			}
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->generate(5);
	//cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
