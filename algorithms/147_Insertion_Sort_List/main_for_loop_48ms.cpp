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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (head) {
            ListNode* tmp = head->next;
            cur = dummy;
            while (cur->next && cur->next->val <= head->val) {
                cur = cur->next;
            }
            head->next = cur->next;
            cur->next = head;
            head = tmp;
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result->next;
    }
};

int main()
{
    Solution * solution = new Solution();
    vector<int> v = { -1,5,3,4,0 };
    ListNode* node = new ListNode(v[0]);
    ListNode* input = node;
    for (int i = 1; i < v.size(); ++i)
    {
        node->next = new ListNode(v[i]);
        node = node->next;
    }
    auto result = solution->insertionSortList(input);
    delete solution;
    //cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
