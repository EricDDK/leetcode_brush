//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes in each of the two partitions.

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        for (int i = 0 ; i < m - 1; ++i) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        for (int i = m; i < n; ++i) {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        return dummy->next;
    }
};

int main()
{
    vector<int> v = { 1,2,3,4,5 };
    ListNode* node = new ListNode(v[0]);
    ListNode* input = node;
    for (int i = 1; i < v.size(); ++i)
    {
        node->next = new ListNode(v[i]);
        node = node->next;
    }
    Solution * solution = new Solution();
    auto result = solution->reverseBetween(input, 1, 5);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
