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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        
        dfs(root, 0, 0, mp);
        
        vector<vector<int>> result;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            sort(it->second.begin(), it->second.end());
            
            vector<int> column;
            for (auto& item: it->second)
                column.push_back(item.second);
            
            result.push_back(column);
        }
        
        return result;
    }
    
    void dfs(TreeNode* root, int row, int column, map<int, vector<pair<int, int>>>& mp) {
        if (root == nullptr)
            return;
        
        dfs(root->left, row + 1, column - 1, mp);
        mp[column].push_back({ row, root->val });
        dfs(root->right, row + 1, column + 1, mp);
    }
};