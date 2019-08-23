//Given a non negative integer number num.For every numbers i in the range 0 ¡Ü i ¡Ü num calculate the number of 
//1's in their binary representation and return them as an array.

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
	vector<int> countBits(int num) {
		if (num == 0)
			return{ 0 };
		vector<int> result{ 0, 1 };
		int i = 2;
		int k = 2;
		while (i <= num)
		{
			for (i = pow(2, k - 1); i < pow(2, k); ++i)
			{
				if (i > num)
					break;
				int t = (pow(2, k) - pow(2, k - 1)) / 2;
				if (i < pow(2, k - 1) + t) 
					result.push_back(result[i - t]);
				else 
					result.push_back(result[i - t] + 1);
			}
			++k;
		}

		return result;
	}
};

int main()
{
	Solution *solution = new Solution;
	if (solution->countBits(2).size() != 3)
		throw;
	if (solution->countBits(5).size() != 3)
		throw;
	delete solution;
	system("pause");
	return 0;
}