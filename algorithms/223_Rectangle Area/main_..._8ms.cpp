//Find the total area covered by two rectilinear rectangles in a 2D plane.
//
//Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

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
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int sum1 = (C - A) * (D - B);
		int	sum2 = (H - F) * (G - E);
		if (E >= C || F >= D || B >= H || A >= G) 
			return sum1 + sum2;
		return sum1 - ((min(G, C) - max(A, E)) * (min(D, H) - max(B, F))) + sum2;
	}
};

int main()
{
	Solution* solution = new Solution;
	if (solution->computeArea(-3, 0, 3, 4, 0, -1, 9, 2) != 45)
		throw;
	delete solution;
	system("pause");
	return 0;
}