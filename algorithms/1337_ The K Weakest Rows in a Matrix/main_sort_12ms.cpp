//Given a m * n matrix mat of ones(representing soldiers) and zeros(representing civilians), return the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.
//
//A row i is weaker than row j, if the number of soldiers in row i is less than the number of soldiers in row j, or they have the same number of soldiers but i is less than j.Soldiers are always stand in the frontier of a row, that is, always ones may appear first and then zeros.

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
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		int n = mat.size(), m = mat[0].size();
		vector<pair<int, int>> a;
		for (int i = 0; i < n; i++) 
		{
			int cnt = 0;
			for (int j = 0; j < m; j++)
				cnt += mat[i][j];
			a.emplace_back(cnt, i);
		}

		sort(a.begin(), a.end());
		vector<int> ans;
		for (int i = 0; i < k; i++)
			ans.push_back(a[i].second);

		return ans;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->kWeakestRows(vector<vector<int>>{
		{1,0}, { 1,0 }, { 1,0 }, { 1,1 },
	}, 4);
	delete solution;
	system("pause");
	return 0;
}