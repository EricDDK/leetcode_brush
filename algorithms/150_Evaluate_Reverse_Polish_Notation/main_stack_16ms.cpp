//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
//Note:
//
//Division between two integers should truncate toward zero.
//The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

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
    int evalRPN(vector<string>& tokens) {
        long long result = 0;
        
        for (string &t : tokens) {
            if (t == "+") {
                int t1 = s.top(); s.pop();
                int t2 = s.top(); s.pop();
                long long tmp = t1 + t2;
                s.push(static_cast<int>(tmp));
            }
            else if (t == "-") {
                int t1 = s.top(); s.pop();
                int t2 = s.top(); s.pop();
                long long tmp = t1 - t2;
                s.push(static_cast<int>(tmp));
            }
            else if (t == "*") {
                int t1 = s.top(); s.pop();
                int t2 = s.top(); s.pop();
                long long tmp = t1 * t2;
                s.push(static_cast<int>(tmp));
            }
            else if (t == "/") {
                int t1 = s.top(); s.pop();
                int t2 = s.top(); s.pop();
                long long tmp = t1 / t2;
                s.push(static_cast<int>(tmp));
            }
            else {
                s.push(atoi(t.c_str()));
            }
        }
        return static_cast<int>(s.top());
    }
    
private:
    stack<long long> s;
};

int main()
{
    Solution * solution = new Solution();
    vector<string> input = { "2", "1", "+", "3", "*" };
    auto result = solution->evalRPN(input);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
