/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 #include <climits>

class Solution {
private:
    bool isValidBSTHelper(TreeNode *node, int minimum, int maximum) {
        if (node == nullptr) {
            return true;
        }
        if (!(node->val < maximum && node->val > minimum)) {
            return false;
        }
        return isValidBSTHelper(node->left, minimum, node->val) &&
                isValidBSTHelper(node->right, node->val, maximum);
    }

public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return isValidBSTHelper(root, INT_MIN, INT_MAX);
    }
};
