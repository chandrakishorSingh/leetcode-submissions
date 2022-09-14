​
Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/
​
class Solution {
public:
vector<int> preorder(Node* root) {
if (root == nullptr)
return vector<int>();
vector<int> result;
result.push_back(root->val);
for (auto& child: root->children) {
for (auto val: preorder(child))
result.push_back(val);
}
return result;
}
};
​
// TC: O(n^2)
// SC: O(n)
```