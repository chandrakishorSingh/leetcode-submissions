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
        if (root == nullptr)
            return {};
        
        vector<int> result;
        stack<TreeNode*> st({root});
        
//         while (root != nullptr) {
//             auto top = st.top();
            
//             if (top->right != nullptr)
//                 st.push(top->right);
            
//             if (top->left != nullptr)
//                 st.push(top->left);
            
//             root = root->left;
//         }
        
        TreeNode* prev = nullptr;
        while (!st.empty()) {
            auto node = st.top();
            
            cout << node->val << " " << (prev == nullptr ? -1 : prev->val) << " " << st.size() << endl;
            if ((node->left == nullptr and node->right == nullptr) or (prev != nullptr and (node->right == prev or node->left == prev))) {
                st.pop();
                prev = node;
                
                result.push_back(node->val);
                continue;
            }
            
            if (node->right != nullptr)
                st.push(node->right);

            if (node->left != nullptr)
                st.push(node->left);
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(n)