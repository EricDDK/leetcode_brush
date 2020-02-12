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

struct Node {
	int value;
	int idx;
	Node(int v, int i) : value(v), idx(i) {}
};

struct cmp {
	bool operator()(Node a, Node b) {
		return a.value > b.value;
	}
};

class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		priority_queue<Node, vector<Node>, cmp> q;
		int i = 0;
		for (auto& ma : mat)
		{
			int t = 0;
			for (auto& m : ma)
			{
				t += m;
			}
			q.push(Node(t, i));
			i++;
		}
		vector<int> result;
		while (k-- > 0)
		{
			result.push_back(q.top().idx);
			q.pop();
		}
		return result;
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