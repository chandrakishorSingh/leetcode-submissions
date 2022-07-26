/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que({root});
        
        TreeNode* result = nullptr;
        while (!que.empty()) {
            auto current = que.front();
            que.pop();
            
            if (hasChild(current, p) && hasChild(current, q))
                result = current;
            
            if (current->left != nullptr)
                que.push(current->left);
            
            if (current->right != nullptr)
                que.push(current->right);
        }
        
        return result;
    }
    
    bool hasChild(TreeNode* root, TreeNode* child) {
        if (root == nullptr)
            return false;
        
        if (root->val == child->val)
            return true;
        
        return hasChild(root->left, child) || hasChild(root->right, child);
    }
};