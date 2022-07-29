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
    void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (root == nullptr)
            return;
        
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        
        int first = -1;
        int second = -1;
        for (int i = 1; i < nodes.size(); i++) {
            if (nodes[i]->val < nodes[i - 1]->val) {
                if (first == -1) {
                    first = i - 1;
                    second = i;
                } else {
                    second = i;
                }
            }
        }
        
        swap(nodes[first]->val, nodes[second]->val);
    }
};

// TC: O(n)
// SC: O(n)