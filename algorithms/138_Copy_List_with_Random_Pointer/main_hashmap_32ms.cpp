//Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
//
//Note:
//
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

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

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node() {}
    
    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        Node* result = new Node(head->val, nullptr, nullptr);
        Node* node = result, *cur = head->next;
        unordered_map<Node*, Node*> map;
        map[head] = result;
        while (cur) {
            Node* tmp = new Node(cur->val, nullptr, nullptr);
            node->next = tmp;
            map[cur] = tmp;
            node = node->next;
            cur = cur->next;
        }
        node = result;
        cur = head;
        while (cur) {
            node->random = map[cur->random];
            node = node->next;
            cur = cur->next;
        }
        return result;
    }
};

int main()
{
    Solution * solution = new Solution();
    Node* input = new Node;
    input->next = new Node;
    input->random = input->next;
    input->next->next = NULL;
    input->next->random = input->next;
    input->val = 1;
    input->next->val = 2;
    auto result = solution->copyRandomList(input);
    delete solution;
    cout << result << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
