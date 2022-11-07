*/
​
class Solution {
public:
vector<int> postorder(Node* root) {
vector<int> result;
postorder(root, result);
return result;
}
void postorder(Node* root, vector<int>& result) {
if (root == nullptr)
return;
for (auto& neighbour: root->children)
postorder(neighbour, result);
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
- Similar to iterative version of the BST postorder traversal.
​
```
​
```