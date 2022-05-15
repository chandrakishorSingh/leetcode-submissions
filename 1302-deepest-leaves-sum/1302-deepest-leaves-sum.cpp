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
    int deepestLeavesSum(TreeNode* root) {
        int maxHeight = height(root);
        
        return getSumAtHeight(root, maxHeight, 1);
    }
    
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        auto leftHeight = height(root->left);
        auto rightHeight = height(root->right);
        
        return max(leftHeight, rightHeight) + 1;
    }
    
    int getSumAtHeight(TreeNode* root, int height, int currentHeight) {
        if (root == nullptr)
            return 0;
        
        auto leftSum = getSumAtHeight(root->left, height, currentHeight + 1);
        auto rightSum = getSumAtHeight(root->right, height, currentHeight + 1);
        
        return leftSum + rightSum + (currentHeight == height ? root->val: 0);
    }
};