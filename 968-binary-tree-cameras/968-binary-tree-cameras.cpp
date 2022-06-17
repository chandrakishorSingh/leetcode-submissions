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
    int minCameraCover(TreeNode* root) {
        placeCameras(root);
        
        return countCamera(root);
    }
    
    void placeCameras(TreeNode* root) {
        if (root == nullptr)
            return;
        
        placeCameras(root->left);
        placeCameras(root->right);
        
        if ((root->left != nullptr && root->left->val == 2) || (root->right != nullptr && root->right->val == 2)) {
            // if possible, try to lift the camera one level up
            if (root->left != nullptr && root->left->val == 2) {
                root->val = 1;
                root->left->val = 0;
            }
            if (root->right != nullptr && root->right->val == 2) {
                root->val = 1;
                root->right->val = 0;
            }
            
            return;
        }
        
        
        // if not possible to lift the camera then see whether light is reaching to current node
        if ((root->left != nullptr && root->left->val == 1) || (root->right != nullptr && root->right->val == 1)) {
            return;
        } else {
            root->val = 2;
        }
    }
    
    int countCamera(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        return countCamera(root->left) + countCamera(root->right) + (root->val != 0 ? 1 : 0);
    }
};