//There are a total of n courses you have to take, labeled from 0 to n-1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
//Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
//
//There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

#include <sstream>
#include "iostream"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include "algorithm"
#include <stack>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in(numCourses, 0);
        for (auto &p : prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            in[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (in[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int t = q.front();
            result.push_back(t);
            q.pop();
            for (auto& a : graph[t])
            {
                --in[a];
                if (in[a] == 0)
                    q.push(a);
            }
        }
        if (result.size() != numCourses)
            result.clear();
        return result;
    }
    
};

int main()
{
    Solution * solution = new Solution();
    vector<vector<int>> input = {{1,0}};
    auto result = solution->findOrder(2, input);
    if (result.empty() || result[0] != 0 || result[1] != 1) {
        throw;
    }
    delete solution;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
