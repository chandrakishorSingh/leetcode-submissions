/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que({root});
        
        while (!que.empty()) {
            Node* next = NULL;
            
            int n = que.size();
            for (int i = 0; i < n; i++) {
                auto node = que.front();
                que.pop();
                
                if (node == NULL) {
                    continue;
                }
                
                node->next = next;
                next = node;
                
                que.push(node->right);
                que.push(node->left);
            }
        }
        
        return root;
    }
};

// TC: O(n)
// SC: O(n)