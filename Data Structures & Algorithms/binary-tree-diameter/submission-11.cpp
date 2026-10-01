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

class Solution {
private:
    int diameter_{0};

    int heightBinaryTree(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }

        int left = heightBinaryTree(node->left);
        int right = heightBinaryTree(node->right);

        diameter_ = std::max(diameter_, left + right);

        return 1 + std::max(left, right);
    }


public:
    int diameterOfBinaryTree(TreeNode *root) {
        heightBinaryTree(root);
        return diameter_;
    }
};
