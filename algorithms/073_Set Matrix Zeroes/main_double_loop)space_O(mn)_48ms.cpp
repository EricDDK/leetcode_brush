//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

#include <sstream>
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
	typedef struct Pos
	{
		int posX;
		int posY;
	} PosInfo;
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty() && matrix[0].empty())
			return;
		vector<PosInfo> posV;
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[0].size(); ++j)
			{
				if (matrix[i][j] == 0)
				{
					PosInfo pos;
					pos.posX = j;
					pos.posY = i;
					posV.push_back(pos);
				}
			}
		}
		for (PosInfo posInfo : posV)
		{
			for (int i = 0; i < matrix.size(); ++i)
			{
				matrix[i][posInfo.posX] = 0;
			}
			for (int i = 0; i < matrix[0].size(); ++i)
			{
				matrix[posInfo.posY][i] = 0;
			}
		}
		return;
	}
private:

};

int main()
{
	Solution* solution = new Solution;
	vector<vector<int>> input = {
		{0,1,1,1},
		{1,1,0,1},
		{1,1,1,1}
	};
	/*auto result = */solution->setZeroes(input);
	//cout << result << endl;
	delete(solution);
	system("pause");
	return 0;
}