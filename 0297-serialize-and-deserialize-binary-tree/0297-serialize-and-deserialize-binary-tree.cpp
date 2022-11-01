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
        vector<TreeNode*> nodes({root});
        
        while (!que.empty()) {
            auto front = que.front();
            que.pop();
            
            if (front == nullptr)
                continue;
            
            que.push(front->left);
            que.push(front->right);
            nodes.push_back(front->left);
            nodes.push_back(front->right);
        }
        
//         for (auto node: nodes)
//             cout << (node == nullptr ? "n " : to_string(node->val)) << " ";
        
//         cout << endl;
        string result = "";
        for (auto node: nodes) {
            // if (node != nullptr)
            //     cout << node->val << " ";
            // else
            //     cout << "n ";
            
            // if (node == nullptr)
            auto value = node == nullptr ? "N" : to_string(node->val);
            for (auto ch: value)
                result.push_back(ch);
            
            result.push_back('$');
        }
        
        return result;
            
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        vector<TreeNode*> nodes({nullptr});
        
        int index = 0;
        while (index < data.size()) {
            int end = index;
            
            while (end < data.size() and data[end] != '$')
                end++;
            
            // cout << index << " " << end << "  ";
            // cout << data.substr(index, end - index) << endl;
            if (data.substr(index, end - index) == "N") {
                nodes.push_back(nullptr);
            } else {
                nodes.push_back(new TreeNode(stoi(data.substr(index, end - index))));
            }
            
            index = end + 1;
        }
        
        int j = 2;
        for (int i = 1; i < nodes.size(); i++) {
            cout << i << " " << (nodes[i] == nullptr ? "n " : to_string(nodes[i]->val)) << endl;
            if (nodes[i] == nullptr)
                continue;
            
            if (j < nodes.size())
                nodes[i]->left = nodes[j++];
            
            if (j < nodes.size())
                nodes[i]->right = nodes[j++];
        }
        
        return nodes.size() == 0 ? nullptr : nodes[1];
    }
    
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));