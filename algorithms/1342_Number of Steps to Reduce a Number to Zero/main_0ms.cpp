

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
	int numberOfSteps(int num) {
		int result = 0;
		while (true)
		{
			if (num % 2 == 0)
			{
				num /= 2;
			}
			else
			{
				num--;
			}
			result++;
			if (num == 0)
			{
				return result;
			}
		}
		return result;
	}
};

int main()
{
	Solution* solution = new Solution;
	
	delete solution;
	system("pause");
	return 0;
}