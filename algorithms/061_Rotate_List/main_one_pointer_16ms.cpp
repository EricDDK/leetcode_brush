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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode *head, int k) {
        if (!head)
            return NULL;
        int n = 1;
        ListNode* cur = head;
        while (cur->next) {
            ++n;
            cur = cur->next;
        }
        cur->next = head;
        int m = n - k % n;
        for (int i = 0; i < m; ++i) {
            cur = cur->next;
        }
        ListNode* result = cur->next;
        cur->next = NULL;
        return result;
    }
};

int main()
{
    Solution* solution = new Solution;
    vector<int> v = { 1,2 };
    ListNode* node = new ListNode(v[0]);
    ListNode* input = node;
    for (int i = 1; i < v.size(); ++i)
    {
        node->next = new ListNode(v[i]);
        node = node->next;
    }
    auto result = solution->rotateRight(input, 3);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
