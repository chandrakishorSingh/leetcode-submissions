/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> clonedNodes;
        unordered_set<int> visited;
        
        dfs(node, clonedNodes, visited);
        
        return clonedNodes.size() == 0 ? nullptr: clonedNodes[1];
    }
    
    void dfs(Node* node, unordered_map<int, Node*>& clonedNodes, unordered_set<int>& visited) {
        if (node == nullptr)
            return;
        
        visited.insert(node->val);
        if (!clonedNodes.count(node->val))
            clonedNodes[node->val] = new Node(node->val);
        
        for (auto neighbor: node->neighbors) {
            if (!clonedNodes.count(neighbor->val)) {
                clonedNodes[neighbor->val] = new Node(neighbor->val);
            }
            
            if (!visited.count(neighbor->val)) {
                dfs(neighbor, clonedNodes, visited);
            }
            
            clonedNodes[node->val]->neighbors.push_back(clonedNodes[neighbor->val]);
        }
    }
};

// TC: O(n + e)
// SC: O(n + e)