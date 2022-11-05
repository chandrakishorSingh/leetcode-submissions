Solution 1(Recursive):
​
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
vector<int> preorderTraversal(TreeNode* root) {
vector<int> result;
preorder(result, root);
return result;
}
void preorder(vector<int>& result, TreeNode* root) {
if (root == nullptr)
return;
result.push_back(root->val);
preorder(result, root->left);
preorder(result, root->right);
}
};
​
// TC: O(n)
// SC: O(n)
```
​
Solution 2