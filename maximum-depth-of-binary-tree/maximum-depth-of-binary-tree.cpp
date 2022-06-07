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
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        
        int leftHeight = INT_MIN;
        if (root->left != nullptr)
            leftHeight = maxDepth(root->left);
        
        int rightHeight = INT_MIN;
        if (root->right != nullptr)
            rightHeight = maxDepth(root->right);
        
        return max(leftHeight, rightHeight) + 1;
    }
};