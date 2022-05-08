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
    int averageOfSubtree(TreeNode* root) {
        int result = 0;
        
        sumAndCountOfSubtree(root, result);
        
        return result;
    }
    
    pair<int, int> sumAndCountOfSubtree(TreeNode* root, int& result) {
        if (root == nullptr)
            return {0, 0};
        
        auto left = sumAndCountOfSubtree(root->left, result);
        auto right = sumAndCountOfSubtree(root->right, result);
        
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;
        
        if (sum / count == root->val)
            result++;
        
        return {sum, count};
    }
};