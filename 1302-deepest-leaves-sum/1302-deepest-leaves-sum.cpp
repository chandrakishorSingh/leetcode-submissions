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
    int maxHeight = 0;
    int sum = 0;
    
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        
        return sum;
    }
    
    void dfs(TreeNode* root, int currentHeight) {
        if (root == nullptr)
            return;
        
        if (maxHeight < currentHeight) {
            maxHeight = currentHeight;
            sum = root->val;
        } else if (maxHeight == currentHeight) {
            sum += root->val;
        }
        
        dfs(root->left, currentHeight + 1);
        dfs(root->right, currentHeight + 1);
    }
};

// TC: O(n)
// SC: O(height of tree)