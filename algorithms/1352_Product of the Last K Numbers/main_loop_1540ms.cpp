//Implement the class ProductOfNumbers that supports two methods :
//
//1. add(int num)
//
//Adds the number num to the back of the current list of numbers.
//2. getProduct(int k)
//
//Returns the product of the last k numbers in the current list.
//You can assume that always the current list has at least k numbers.
//At any time, the product of any contiguous sequence of numbers will fit into a single 32 - bit integer without overflowing.

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

class ProductOfNumbers {
public:
	ProductOfNumbers() {

	}

	void add(int num) {
		v.push_back(num);
	}

	int getProduct(int k) {
		int result = 1;
		int index = v.size() - 1;
		for (; k > 0; --k)
		{
			result *= v[index--];
		}
		return result;
	}

private:
	vector<int> v;
};

int main()
{
	//Solution* solution = new Solution;
	
	//delete solution;
	system("pause");
	return 0;
}