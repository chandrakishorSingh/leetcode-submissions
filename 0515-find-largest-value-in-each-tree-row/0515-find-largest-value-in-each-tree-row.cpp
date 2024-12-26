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
    void dfs(int level, TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        
        if (level > result.size()) {
            result.push_back(node->val);
        } else {
            result[level - 1] = max(result[level - 1], node->val);
        }
        
        dfs(level + 1, node->left, result);
        dfs(level + 1, node->right, result);
    }

public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        
        dfs(1, root, result);
        
        return result;
    }
};