/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

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

        string result = "";
        for (auto node: nodes) {
            auto value = node == nullptr ? "N" : to_string(node->val);
            for (auto ch: value)
                result.push_back(ch);
            
            result.push_back('$');
        }
        
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> nodes;
        
        int index = 0;
        while (index < data.size()) {
            int end = index;
            
            while (end < data.size() and data[end] != '$')
                end++;
            
            auto nodeValue = data.substr(index, end - index);
            if (nodeValue == "N") {
                nodes.push_back(nullptr);
            } else {
                nodes.push_back(new TreeNode(stoi(nodeValue)));
            }
            
            index = end + 1;
        }
        
        int j = 1;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == nullptr)
                continue;
            
            if (j < nodes.size())
                nodes[i]->left = nodes[j++];
            
            if (j < nodes.size())
                nodes[i]->right = nodes[j++];
        }
        
        return nodes.size() == 0 ? nullptr : nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// serialize: TC: O(n), SC: (n)
// deserialize: TC: O(n), SC: O(n)
