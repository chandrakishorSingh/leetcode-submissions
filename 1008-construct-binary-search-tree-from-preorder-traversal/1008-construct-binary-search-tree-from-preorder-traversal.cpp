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
    
    TreeNode* dfs(vector<int>& preorder, int left, int right) {
        if (left > right)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[left]);
        int i = left;
        int j = right + 1;
        
        while ((i + 1 < j) && (preorder[i + 1] < root->val)) i++;
        while ((j - 1 > i) && (preorder[j - 1] > root->val)) j--;
        
        root->left = dfs(preorder, left + 1, i);
        root->right = dfs(preorder, j, right);
        
        return root;
    }
};

// TC: O(n^2)
// SC: O(n)