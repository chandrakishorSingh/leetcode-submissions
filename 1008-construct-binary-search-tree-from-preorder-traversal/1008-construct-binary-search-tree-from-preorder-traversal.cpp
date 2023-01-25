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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* result = new TreeNode(preorder[0]);
        
        stack<TreeNode*> st;
        st.push(result);
        
        for (int i = 1; i < preorder.size(); i++) {
            auto node = new TreeNode(preorder[i]);
            
            TreeNode* top = nullptr;
            while (!st.empty() && st.top()->val < node->val) {
                top = st.top();
                st.pop();
            }
            
            if (top != nullptr) {
                top->right = node;
            } else if (!st.empty()) {
                st.top()->left = node;
            }
            
            st.push(node);
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(n)