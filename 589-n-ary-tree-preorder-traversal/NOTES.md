*/
​
class Solution {
public:
vector<int> preorder(Node* root) {
vector<int> result;
dfs(root, result);
return result;
}
void dfs(Node* root, vector<int>& result) {
if (root == nullptr)
return;
result.push_back(root->val);
for (auto& child: root->children)
dfs(child, result);
}
};
​
// TC: O(n)
// SC: O(n)
```
​