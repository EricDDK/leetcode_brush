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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* small = new ListNode(-1);
        ListNode* big = new ListNode(-1);
        ListNode* a = small;
        ListNode* b = big;
        while (head) {
            if (head->val < x) {
                small->next = new ListNode(head->val);
                small = small->next;
            }
            else {
                big->next = new ListNode(head->val);
                big = big->next;
            }
            head = head->next;
        }
        ListNode* result = a;
        small->next = b->next;
        result = result->next;
        delete a;
        delete b;
        return result;
    }
};

int main()
{
    vector<int> v = { 1,1 };
    ListNode* node = new ListNode(v[0]);
    ListNode* input = node;
    for (int i = 1; i < v.size(); ++i)
    {
        node->next = new ListNode(v[i]);
        node = node->next;
    }
    Solution * solution = new Solution();
    auto result = solution->partition(input, 0);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
