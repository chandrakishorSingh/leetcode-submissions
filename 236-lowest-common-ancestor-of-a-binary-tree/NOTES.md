Solution 1:
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
que.pop();
if (hasChild(current, p) && hasChild(current, q))
result = current;
if (current->left != nullptr)
que.push(current->left);
if (current->right != nullptr)
que.push(current->right);
}
return result;
}
bool hasChild(TreeNode* root, TreeNode* child) {
if (root == nullptr)
return false;
if (root->val == child->val)
return true;
return hasChild(root->left, child) || hasChild(root->right, child);
}
};
​
// TC: O(n^2)
// SC: O(n)
```