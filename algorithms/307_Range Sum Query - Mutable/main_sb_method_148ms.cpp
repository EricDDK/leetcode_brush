//Given an integer array nums, find the sum of the elements between indices i and j(i ¡Ü j), inclusive.
//
//The update(i, val) function modifies nums by updating the element at index i to val.

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

class NumArray {
public:
	NumArray(vector<int> nums) {
		data = nums;
	}

	void update(int i, int val) {
		data[i] = val;
	}

	int sumRange(int i, int j) {
		int sum = 0;
		for (int k = i; k <= j; ++k) 
		{
			sum += data[k];
		}
		return sum;
	}

private:
	vector<int> data;
};

int main()
{
	vector<int> input = {1,3,5};
	NumArray na(input);
	if (na.sumRange(0, 2) != 9)
		throw;
	na.update(1, 2);
	if (na.sumRange(0, 2) != 8)
		throw;

	input = {-1};
	na = NumArray(input);
	if (na.sumRange(0, 0) != -1)
		throw;
	na.update(0, 1);
	if (na.sumRange(0, 0) != 1)
		throw;
	system("pause");
	return 0;
}