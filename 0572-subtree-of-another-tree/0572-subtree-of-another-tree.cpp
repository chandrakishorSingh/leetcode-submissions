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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return false;
        
        if (isTreeSame(root, subRoot))
            return true;
        
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
    
    bool isTreeSame(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr and subRoot == nullptr)
            return true;
        
        if (root == nullptr or subRoot == nullptr or root->val != subRoot->val)
            return false;
        
        return isTreeSame(root->left, subRoot->left) and isTreeSame(root->right, subRoot->right);
    }
};