Solution 1:
​
- Here, I've used the LC way of representing a serialization version of the binary tree.
- The nodes are ordered in such a way that first root is inserted into the sequence. Then for every node in the sequence, both of it's child are inserted. If any of it's child is missing(left or right), a symbol indicating null pointer is inserted.
- So, both of the given methods just require one DFS.
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
class Codec {
public:
​
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
queue<TreeNode*> que({root});
vector<TreeNode*> nodes;
while (!que.empty()) {
auto front = que.front();
que.pop();
nodes.push_back(front);
if (front == nullptr)
continue;
que.push(front->left);
que.push(front->right);
}
​
string result = "";
for (auto node: nodes) {
auto value = node == nullptr ? "N" : to_string(node->val);
for (auto ch: value)
result.push_back(ch);
result.push_back('$');
}
return result;