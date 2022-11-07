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