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
        auto path1 = getPath(root, p);
        auto path2 = getPath(root, q);
        
        int n1 = path1.size();
        int n2 = path2.size();
        int it1 = n1 - 1;
        int it2 = n2 - 1;
        TreeNode* result = nullptr;
        for (int i = 0; i < min(n1, n2); i++, it1--, it2--) {
            if (path1[it1]->val != path2[it2]->val)
                break;
            
            result = path1[it1];
        }
        
        return result;
    }
    
    vector<TreeNode*> getPath(TreeNode* root, TreeNode* child) {
        vector<TreeNode*> result;
        bool isChildSeen = false;
        dfs(root, child, result, isChildSeen);
        
        return result;
    }
    
    void dfs(TreeNode* root, TreeNode* child, vector<TreeNode*>& result, bool& isChildSeen) {
        if (root == nullptr)
            return;
        
        if (root->val == child->val) {
            isChildSeen = true;
            result.push_back(root);
            return;
        }
        
        dfs(root->left, child, result, isChildSeen);
        
        if (isChildSeen) {
            result.push_back(root);
            return;
        }
        
        dfs(root->right, child, result, isChildSeen);
        
        if (isChildSeen)
            result.push_back(root);
    }
};

// TC: O(n^2)
// SC: O(n)