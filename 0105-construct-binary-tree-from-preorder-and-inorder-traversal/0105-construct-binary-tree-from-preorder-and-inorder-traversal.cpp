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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        int start = 0;
        int end = inorder.size() - 1;
        
        unordered_map<int, int> indices;
        for (int i = 0; i < inorder.size(); i++)
            indices[inorder[i]] = i;
        
        return buildTree(preorder, inorder, indices, i, start, end);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& indices, int& i, int start, int end) {
        if (start > end)
            return nullptr;
        
        int index = indices[preorder[i++]];
        auto node = new TreeNode(inorder[index]);
        
        node->left = buildTree(preorder, inorder, indices, i, start, index - 1);
        node->right = buildTree(preorder, inorder, indices, i, index + 1, end);
        
        return node;
    }
};

// TC: Θ(n)
// SC: O(n)