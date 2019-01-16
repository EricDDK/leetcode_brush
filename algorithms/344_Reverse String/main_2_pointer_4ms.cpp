//Given an integer(signed 32 bits), write a function to check whether it is a power of 4.

#include<sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		int left = 0;
		int right = s.size() - 1;
		while (left < right)
		{
			char tmp = s[right];
			s[right--] = s[left];
			s[left++] = tmp;
		}
		return s;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->reverseString("hello");
	cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}