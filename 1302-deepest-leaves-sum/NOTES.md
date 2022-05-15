}
int height(TreeNode* root) {
if (root == nullptr)
return 0;
auto leftHeight = height(root->left);
auto rightHeight = height(root->right);
return max(leftHeight, rightHeight) + 1;
}
int getSumAtHeight(TreeNode* root, int height, int currentHeight) {
if (root == nullptr)
return 0;
auto leftSum = getSumAtHeight(root->left, height, currentHeight + 1);
auto rightSum = getSumAtHeight(root->right, height, currentHeight + 1);
return leftSum + rightSum + (currentHeight == height ? root->val: 0);
}
};
​
// TC: O(n)
// SC: O(height of tree)
```