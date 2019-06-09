//Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
//Example:
//
//Input: [1,2,3,null,5,null,4]
//Output: [1, 3, 4]
//Explanation:
//
//1            <---
///   \
//2     3         <---
//\     \
//5     4       <---

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *tmp = root;
        while (!q.empty()) {
            v.push_back(q.back()->val);
            size_t size = q.size();
            for (int i = 0; i < size; ++i) {
                tmp = q.front();
                q.pop();
                if (tmp->left) {
                    q.push(tmp->left);
                }
                if (tmp->right) {
                    q.push(tmp->right);
                }
            }
        }
        return v;
    }
private:
    vector<int> v;
};

int main()
{
    Solution * solution = new Solution();
    TreeNode *input = new TreeNode(1);
    input->left = new TreeNode(2);
    input->right = new TreeNode(3);
    input->left->right = new TreeNode(5);
    input->right->right = new TreeNode(4);
    auto res = solution->rightSideView(input);
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
