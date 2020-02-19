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
		if (num == 0)
			v.clear();
		else
		{
			if (v.size() == 0)
				v.push_back(num);
			else
				v.push_back(v.back() * num);
		}
	}

	int getProduct(int k) {
		if (k == v.size())
			return v.back();
		else if (k > v.size())
			return 0;
		else
			return v[v.size() - 1] / v[v.size() - 1 - k];
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