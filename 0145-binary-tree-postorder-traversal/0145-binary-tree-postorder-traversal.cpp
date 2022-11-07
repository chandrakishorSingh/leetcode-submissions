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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        
        while (root != nullptr) {
            st.push(root);
            result.push_back(root->val);
            
            root = root->right;
        }
        
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            
            node = node->left;
            while (node != nullptr) {
                st.push(node);
                result.push_back(node->val);
                
                node = node->right;
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

// TC: O(n)
// SC: O(n)