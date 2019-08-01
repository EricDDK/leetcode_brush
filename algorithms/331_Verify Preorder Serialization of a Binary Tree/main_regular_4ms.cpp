//One way to serialize a binary tree is to use pre - order traversal.When we encounter a non - null node, 
//we record the node's value. If it is a null node, we record using a sentinel value such as #.

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
	bool isValidSerialization(string preorder) {
		int capacity = 1;
		preorder += ",";
		for (int i = 0; i < preorder.size(); ++i)
		{
			if (preorder[i] != ',') 
				continue;
			if (--capacity < 0) 
				return false;
			if (preorder[i - 1] != '#') 
				capacity += 2;
		}
		return capacity == 0;
	}
};

int main()
{
	Solution *solution = new Solution;
	if (!solution->isValidSerialization("9,#,93,#,9,9,#,#,#"))
		throw;
	if (!solution->isValidSerialization("9,#,92,#,#"))
		throw;
	if (!solution->isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"))
		throw;
	if (solution->isValidSerialization("1,#"))
		throw;
	if (solution->isValidSerialization("9,#,#,1"))
		throw;
	delete solution;
	system("pause");
	return 0;
}