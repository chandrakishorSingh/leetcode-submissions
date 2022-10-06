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
        unordered_map<int, vector<int>> adjList;
        
        dfs(node, adjList);
        
        int n = adjList.size();
        // cout << n << node->val << endl;
        vector<Node*> nodes(n + 1, nullptr);
        for (int i = 1; i <= n; i++)
            nodes[i] = new Node(i);
        
        for (auto it: adjList) {
            int currentNode = it.first;
            for (auto neighbor: it.second) {
                nodes[currentNode]->neighbors.push_back(nodes[neighbor]);
            }
        }
        
        return n == 0 ? nullptr: nodes[1];
    }
    
    void dfs(Node* node, unordered_map<int, vector<int>>& adjList) {
        if (node == nullptr)
            return;
        
        adjList[node->val] = vector<int>();
        
        for (auto neighbor: node->neighbors) {
            adjList[node->val].push_back(neighbor->val);
        }
        
        for (auto neighbor: node->neighbors) {
            if (!adjList.count(neighbor->val))
                dfs(neighbor, adjList);
        }
    }
};