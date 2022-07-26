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
        TreeNode* result = nullptr;
        bool isFirstSeen = false;
        bool isSecondSeen = false;
        
        dfs(root, p, q, result, isFirstSeen, isSecondSeen);
        
        return result;
    }
    
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& result, bool& isFirstSeen, bool& isSecondSeen) {
        if (root == nullptr)
            return;
        
        if (root->val == p->val) {
            isFirstSeen = true;
            result = root;
        }
        
        if (root->val == q->val) {
            isSecondSeen = true;
            result = root;
        }
        
        if (isFirstSeen) {
            if (hasChild(root, q))
                isSecondSeen = true;
            
            return;
        }
        
        if (isSecondSeen) {
            if (hasChild(root, p))
                isFirstSeen = true;
            
            return;
        }
        
        dfs(root->left, p, q, result, isFirstSeen, isSecondSeen);
        
        if (isFirstSeen && isSecondSeen)
            return;
        
        if (isFirstSeen || isSecondSeen) {
            if (isFirstSeen) {
                if (hasChild(root->right, q)) {
                    result = root;
                    isSecondSeen = true;
                }
                
                return;
            }
            
            if (isSecondSeen) {
                if (hasChild(root->right, p)) {
                    result = root;
                    isFirstSeen = true;
                }
                
                return;
            }
        }
        
        dfs(root->right, p, q, result, isFirstSeen, isSecondSeen);
    }
    
    bool hasChild(TreeNode* root, TreeNode* child) {
        if (root == nullptr)
            return false;
        
        if (root->val == child->val)
            return true;
        
        return hasChild(root->left, child) || hasChild(root->right, child);
    }
};

// TC: O(n)
// SC: O(n)