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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        
        return dfs(root, targetSum, root->val);
    }
    
    bool dfs(TreeNode* root, int targetSum, int currentSum) {
        if (root->left == nullptr && root->right == nullptr)
            return currentSum == targetSum;
            
        bool isTargetFound = false;
        if (root->left)
            isTargetFound = dfs(root->left, targetSum, currentSum + root->left->val);
        
        if (isTargetFound)
            return true;
        
        if (root->right)
            isTargetFound = dfs(root->right, targetSum, currentSum + root->right->val);
        
        return isTargetFound;
    }
};