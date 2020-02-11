

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
	double angleClock(int hour, int minutes) {
		hour %= 12;
		double m = 6 * minutes;
		double h = 0.5 * minutes + hour * 30.0;
		double result = abs(m - h);
		return result > 180.0 ? (360.0 - result) : result;
	}
};

int main()
{
	Solution* solution = new Solution;
	auto result = solution->angleClock(12, 30);
	if (result != 165) throw;
	result = solution->angleClock(3, 30);
	if (result != 75) throw;
	result = solution->angleClock(3, 15);
	if (result != 7.5) throw;
	result = solution->angleClock(4, 50);
	if (result != 155) throw;
	result = solution->angleClock(12, 0);
	if (result != 0) throw;
	result = solution->angleClock(1, 57);
	if (result != 76.5) throw;
	delete solution;
	system("pause");
	return 0;
}