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
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }
    
    bool dfs(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr)
            return true;
        
        if ((node1 == nullptr && node2 != nullptr) || (node1 != nullptr && node2 == nullptr))
            return false;
        
        if (node1->val != node2->val)
            return false;
        
        return dfs(node1->right, node2->left) && dfs(node1->left, node2->right);
    }
};