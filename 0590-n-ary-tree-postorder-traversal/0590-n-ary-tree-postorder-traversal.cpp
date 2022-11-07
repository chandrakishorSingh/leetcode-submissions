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
        stack<Node*> st({root});
        
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            
            if (node == nullptr)
                continue;
            
            result.push_back(node->val);
            
            for (auto& neighbour: node->children)
                st.push(neighbour);
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};

// TC: O(n)
// SC: O(n)