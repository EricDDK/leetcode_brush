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

struct Side {
    TreeNode *root;
    int height;
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return v;
        queue<Side> q;
        q.push(Side{root, 0});
        v.push_back(root->val);
        while (!q.empty()) {
            Side tmp = q.front();
            q.pop();
            if (tmp.root->left) {
                q.push(Side{tmp.root->left, tmp.height + 1});
                push(tmp.root->left->val, tmp.height + 1);
            }
            if (tmp.root->right) {
                q.push(Side{tmp.root->right, tmp.height + 1});
                push(tmp.root->right->val, tmp.height + 1);
            }
        }
        return v;
    }
private:
    void push(int value, int index) {
        if (v.size() < index + 1) {
            v.push_back(value);
        }
        else {
            v[index] = value;
        }
    }
    
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
