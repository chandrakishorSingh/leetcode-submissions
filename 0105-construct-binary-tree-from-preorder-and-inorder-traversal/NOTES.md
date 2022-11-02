Solution 1:
​
- Observations
- In inorder traversal, for every node in the tree, all of the nodes in its left subtree will be to the left of this node and all of the nodes in the right subtree will be right of this node.
- In preorder traversal, for every node in tree, all of nodes in its subtree will be right of it and all of the nodes in the right subtree will be to the right of every node in its left subtree.
- Initially, we can use the first node(root) of preorder to split the inorder sequence into left and right part which obviously contains all of the nodes in the left and right of the root respectively.
- Then, after the root node, all of its left children are present before its right children in the preorder traversal. But the question is how to find the index at which left children ends and right children begins ? It's simple. Until the left sequence has even 1 node in it we can be sure that right children are not reached at.
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
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
int i = 0;
int start = 0;
int end = inorder.size() - 1;