//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

#include "iostream"
#include <vector>
#include <unordered_map>
#include <map>
#include <hash_set>
#include "windows.h"
#include "algorithm"
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int count = m + n - 1;
		--m;
		--n;
		while (n >= 0)
		{
			if (m >= 0 && nums1[m] >= nums2[n])
			{
				nums1[count--] = nums1[m--];
			}
			else
			{
				nums1[count--] = nums2[n--];
			}
		}
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input1 = { 4,5,6, 0, 0, 0 };
	vector<int> input2 = { 1,2,3 };
	solution->merge(input1, 3, input2, 3);
	//cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
