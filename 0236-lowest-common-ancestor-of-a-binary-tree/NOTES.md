Solution 1(Brute-Force):
​
- From every node of the tree, check whether the given two nodes are its descendant or not.
- The order of checking will be in a bfs manner so that we will be sure that the last node which have both of the given nodes as its descendant will be the answer.
- Worse case would happen when tree is skewed.
​
```
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
queue<TreeNode*> que({root});
TreeNode* result = nullptr;
while (!que.empty()) {
auto current = que.front();