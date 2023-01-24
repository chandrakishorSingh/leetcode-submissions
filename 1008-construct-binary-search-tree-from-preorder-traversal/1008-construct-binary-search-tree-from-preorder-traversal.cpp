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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size() - 1);
    }
    
    TreeNode* dfs(vector<int>& preorder, int left, int right) {
        if (left > right)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[left]);
        int i = left;
        int j = right + 1;
        
        while ((i + 1 < j) && (preorder[i + 1] < root->val)) i++;
        while ((j - 1 > i) && (preorder[j - 1] > root->val)) j--;
        
        root->left = dfs(preorder, left + 1, i);
        root->right = dfs(preorder, j, right);
        
        return root;
    }
};