//You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.
//
//If node i has no left child then leftChild[i] will equal - 1, similarly for the right child.
//
//Note that the nodes have no values and that we only use the node numbers in this problem.

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
#include <numeric>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif // _MSC_VER

using namespace std;

class Solution {
public:
	using VI = vector<int>;
	VI closestDivisors(int x, int a = 0, int b = 0, int diff = int(1e9 + 7)) {
		for (auto i = 1; i * i <= x + 2; ++i) 
		{
			auto j = (x + 1) / i,
				k = (x + 2) / i;
			if (i * j == x + 1 && abs(i - j) < diff) 
				a = i, b = j, diff = abs(i - j);
			if (i * k == x + 2 && abs(i - k) < diff) 
				a = i, b = k, diff = abs(i - k);
		}
		return { a, b };
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->closestDivisors(8);
	delete solution;
	system("pause");
	return 0;
}