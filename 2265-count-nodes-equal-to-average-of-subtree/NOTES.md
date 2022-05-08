Solution 1:
​
- Simple DFS to obtain the sum and count of nodes in the subtree rooted at current node.
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
int averageOfSubtree(TreeNode* root) {
int result = 0;
sumAndCountOfSubtree(root, result);
return result;