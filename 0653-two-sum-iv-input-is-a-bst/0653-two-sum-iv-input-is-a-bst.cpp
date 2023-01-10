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
    bool findTarget(TreeNode* root, int k) {
        TreeNode* current = root;
        
        stack<TreeNode*> st1;
        while (current != nullptr) {
            st1.push(current);
            current = current->left;
        }
        
        current = root;
        stack<TreeNode*> st2;
        while (current != nullptr) {
            st2.push(current);
            current = current->right;
        }
        
        auto left = st1.top();  st1.pop();
        auto right = st2.top(); st2.pop();
        while (left != right) {
            int sum = left->val + right->val;

            if (sum == k)
                return true;
            
            if (sum < k) {
                current = left->right;
                while (current != nullptr) {
                    st1.push(current);
                    current = current->left;
                }
                
                left = st1.top();
                st1.pop();
            } else {
                current = right->left;
                while (current != nullptr) {
                    st2.push(current);
                    current = current->right;
                }
                
                right = st2.top();
                st2.pop();
            }
        }
        
        return false;
    }
};