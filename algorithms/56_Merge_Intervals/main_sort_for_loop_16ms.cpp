//Given a collection of intervals, merge all overlapping intervals.

#include<sstream>
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

struct Interval {
    int start;
    int end;
    Interval():start(0), end(0){};
    Interval(int s, int e):start(s), end(e){};
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {return a.start < b.start;});
        vector<Interval> result(1, intervals[0]);
        int index = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= result[index].end) {
                result[index].start = min(intervals[i].start, result[index].start);
                result[index].end = max(intervals[i].end, result[index].end);
            }
            else{
                result.push_back(intervals[i]);
                index++;
            }
        }
        
        return result;
    }
};

int main()
{
    Solution* solution = new Solution;
    vector<Interval> input;
    input.push_back(Interval(1,4));
    input.push_back(Interval(0,2));
    input.push_back(Interval(3,5));
//    input.push_back(Interval(15,18));
    auto result = solution->merge(input);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
