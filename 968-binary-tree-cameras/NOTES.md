Solution 1:
​
- We are trying to find the result for bigger trees using the results for smaller tree.
- We take two BT where cameras have been installed in optimal way. Then we try to combine them(in "correct" way) using one node to form a bigger tree and calculate the result for big tree.
- Smallest BT with correct camera config. would be with one node and one camera.
- Since in every step the height of the tree is increased by one, we will try to move the camera one level up(if it's possible) so that its light can reach to nodes above and below it.
- We will label cameras/nodes as follows.
- 2: A camera which can be moved one level up. A camera which is installed at current level can be moved up by one level.
- 1: A camera which has been moved one level up. Now it can't be moved one more level up as it's children won't get the light from this one.
- 0: A node where light is reaching either from its parent or from its child.
​
​
```
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
int minCameraCover(TreeNode* root) {
placeCameras(root);
return countCamera(root);
}
void placeCameras(TreeNode* root) {
if (root == nullptr)
return;
placeCameras(root->left);
placeCameras(root->right);
// 0(after traversing it): camera not present here but light is reaching from child nodes
// 1: camera is present here but it can't be lifted one level up as it's child are dependent on this light