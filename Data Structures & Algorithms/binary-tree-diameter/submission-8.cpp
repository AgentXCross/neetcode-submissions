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
    int diameter_ = 0;

    int height_binary_tree(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }

        int left_height = height_binary_tree(node->left);
        int right_height = height_binary_tree(node->right);

        diameter_ = std::max(diameter_, left_height + right_height);

        return 1 + std::max(left_height, right_height);
    }

public:
    int diameterOfBinaryTree(TreeNode *root) {
        height_binary_tree(root);
        return diameter_;
    }
};
