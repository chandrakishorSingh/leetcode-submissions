Solution 1:
​
- Remember that the inorder traversal of a BST gives the elements in increasing order.
- We can use this fact to find elements which are not in order.
- Since only 2 values have been swapped, it's easy to identify those. The first time we encounter pair of successive elements such that the previous one is greater than the next one, we will set the two nodes to those. If we encounter them the second time then it means second node will be the one which is smaller.
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
void inorder(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second) {
if (root == nullptr)
return;
inorder(root->left, prev, first, second);
if (prev != nullptr) {
if (prev->val > root->val) {
if (first == nullptr) {
first = prev;
second = root;
} else {
second = root;
}
}
}
prev = root;
inorder(root->right, prev, first, second);
}
void recoverTree(TreeNode* root) {
TreeNode* prev = nullptr;
TreeNode* first = nullptr;
TreeNode* second = nullptr;
inorder(root, prev, first, second);
swap(first->val, second->val);
}
};
​
// TC: O(n)
// SC: O(n)
```