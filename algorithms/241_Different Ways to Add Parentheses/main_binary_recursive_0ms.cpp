//Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :
//
//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.

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
	vector<int> diffWaysToCompute(string input) {
		vector<int> result;
		int j, k;
		for (int i = 0; i < input.size(); ++i)
		{
			if (input[i] == '+' || input[i] == '-' || input[i] == '*')
			{
				auto left = diffWaysToCompute(input.substr(0, i));
				auto right = diffWaysToCompute(input.substr(i + 1));
				for (j = 0; j < left.size(); ++j)
				{
					for (k = 0; k < right.size(); ++k)
					{
						if (input[i] == '+') 
							result.push_back(left[j] + right[k]);
						else if (input[i] == '-') 
							result.push_back(left[j] - right[k]);
						else 
							result.push_back(left[j] * right[k]);
					}
				}
			}
		}
		if (result.empty())
			result.push_back(stoi(input));
		return result;
	}

private:
	
};

int main()
{
	Solution* solution = new Solution;
	if (solution->diffWaysToCompute("2-1-1").size() != 2)
		throw;
	if (solution->diffWaysToCompute("2*3-4*5").size() != 5)
		throw;
	delete solution;
	system("pause");
	return 0;
}