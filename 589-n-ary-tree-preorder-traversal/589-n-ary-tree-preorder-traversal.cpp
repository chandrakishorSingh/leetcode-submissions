/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

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

// TC: O(n)
// SC: O(n)