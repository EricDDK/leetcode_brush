//The count - and - say sequence is the sequence of integers with the first five terms as following :

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
	string countAndSay(int n) {
		if (n <= 0)
		{
			return "";
		}
		string res = "1";
		while (--n)
		{
			string cur = "";
			for (int i = 0; i < res.size(); ++i) {
				int cnt = 1;
				while (i + 1 < res.size() && res[i] == res[i + 1]) {
					++cnt;
					++i;
				}
				cur += to_string(cnt) + res[i];
			}
			res = cur;
		}
		return res;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->countAndSay(4);
	cout << result << endl;
	delete solution;
	system("pause");
	return 0;
}
