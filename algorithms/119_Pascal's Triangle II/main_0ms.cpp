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
	vector<int> getRow(int numRows) {
		numRows++;
		if (numRows <= 2)
		{
			vector<int> result(numRows,1);
			return result;
		}
		vector<int> last(2,1);
		vector<int> result(2,1);
		for (int i = 3; i <= numRows; i++)
		{
			result.resize(i,2);
			result[i - 1] = 1;
			for (int j = 1; j < i-1; j++)
			{
				result[j] = last[j - 1] + last[j];
			}
			last = result;
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->getRow(3);
	//cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
