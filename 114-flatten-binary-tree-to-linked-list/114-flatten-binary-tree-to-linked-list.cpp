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
    void flatten(TreeNode* root) {
        TreeNode* tail = nullptr;
        preorder(root, tail);
    }
    
    void preorder(TreeNode* root, TreeNode*& tail) {
        if (root == nullptr)
            return;
        
        auto rightSubTree = root->right;
        auto leftSubTree = root->left;
        
        if (tail != nullptr) {
            tail->left = nullptr;
            tail->right = root;
        }
        
        tail = root;
        
        preorder(leftSubTree, tail);
        preorder(rightSubTree, tail);
        
        root->left = nullptr;
    }
};