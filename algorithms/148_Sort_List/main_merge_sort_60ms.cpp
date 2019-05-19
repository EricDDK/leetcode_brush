//Sort a linked list using insertion sort.
//
//
//A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
//With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
//
//
//Algorithm of Insertion Sort:
//
//Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
//At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
//It repeats until no input elements remain.

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1)
            cur->next = l1;
        if (l2)
            cur->next = l2;
        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
    
};

int main()
{
    Solution * solution = new Solution();
    vector<int> v = { 4,2,1,3 };
    ListNode* node = new ListNode(v[0]);
    ListNode* input = node;
    for (int i = 1; i < v.size(); ++i)
    {
        node->next = new ListNode(v[i]);
        node = node->next;
    }
    auto result = solution->sortList(input);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
