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
        stack<TreeNode*> st;
        st.push(new TreeNode(preorder.front()));
        
        TreeNode* result = st.top();
        for (int i = 1; i < preorder.size(); i++) {
            auto node = new TreeNode(preorder[i]);
            
            if (st.empty()) {
                st.push(node);
                continue;
            }
            
            if (st.top()->val > node->val) {
                st.top()->left = node;
                st.push(node);
                continue;
            }
            
            TreeNode* parent = nullptr;
            while (!st.empty() && st.top()->val < node->val) {
                parent = st.top();
                st.pop();
            }
            
            parent->right = node;
            st.push(node);
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(n)