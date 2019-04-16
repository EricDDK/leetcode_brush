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
		if (n==0)
		{
			return;
		}
		for (int i = nums1.size() - 1; i >= n; --i)
		{
			int tmp = nums1[i];
			nums1[i] = nums1[i - n];
			nums1[i - n] = tmp;
		}
		int a = n, b = 0;
		while (a <= m + n && b != n)
		{
			if (a < m + n && nums1[a] <= nums2[b])
			{
				nums1[a + b - n] = nums1[a];
				a++;
			}
			else
			{
				nums1[a + b - n] = nums2[b];
				b++;
			}
		}
	}
};

int main()
{
	Solution* solution = new Solution;
	vector<int> input1 = { 1, 2, 3, 0, 0, 0 };
	vector<int> input2 = { 2, 5, 6 };
	solution->merge(input1, 3, input2, 3);
	//cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
