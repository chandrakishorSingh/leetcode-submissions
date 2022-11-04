```
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
vector<int> inorderTraversal(TreeNode* root) {
stack<TreeNode*> st;
while (root != nullptr) {
st.push(root);
root = root->left;
}
vector<int> result;
while (!st.empty()) {
auto node = st.top();
st.pop();
result.push_back(node->val);
node = node->right;
while (node != nullptr) {
st.push(node);
node = node->left;
}
}
return result;
}
};
​
// TC: O(n)
// SC: O(n)
```