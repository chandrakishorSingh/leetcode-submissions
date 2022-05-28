Solution 1:
​
- Simple DFS
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
bool hasPathSum(TreeNode* root, int targetSum) {
if (root == nullptr)
return false;
return dfs(root, targetSum, 0);
}
bool dfs(TreeNode* root, int targetSum, int currentSum) {
if (root == nullptr)
return false;
if (root->left == nullptr && root->right == nullptr)
return currentSum + root->val == targetSum;
return dfs(root->left, targetSum, currentSum + root->val) || dfs(root->right, targetSum, currentSum + root->val);
}
};
​
// TC: O(n)
// SC: O(height of tree)
```