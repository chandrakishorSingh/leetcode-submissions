void postorder(TreeNode* root, vector<int>& result) {
if (root == nullptr)
return;
postorder(root->left, result);
postorder(root->right, result);
result.push_back(root->val);
}
};
​
// TC: O(n)
// SC: O(n)
```
​
Solution 2(Iterative):
​
- In postorder traversal, the idea is to first print the nodes in the left subtree then right subtree and finally the root of this tree.
- So, the order is L-R-root. Hence when we're at a given tree, we should first push its right child and then left child. In this way, the top of the stack will always be left child and hence left nodes will be printed first before the right nodes.
- How to know when to print a node ? Then answer is that we should print a node after all of its child nodes have been printed.
- If the node(which is at top of the stack) is a leaf node then we have to print it(as in a sense we can say that we have already explored it's children). Otherwise, if the node which was printed before the node present at the top of the stack is it's either left or right child then it means all of its left and right child nodes have been printed and we should print this node as well. Otherwise, this node's children are not printed yet and so we need to push it's immediate right and left child to continue the process.
​
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
vector<int> postorderTraversal(TreeNode* root) {
if (root == nullptr)
return {};
vector<int> result;
stack<TreeNode*> st({root});
TreeNode* prev = nullptr;