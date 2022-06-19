class TrieNode {
public:
    vector<TrieNode*> children;
    set<string> suggestions;
    
    TrieNode() {
        children.resize(26);
    }
};

class Trie {
private:
    TrieNode* root;
    
public:    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string& s) {
        auto current = root;
        for (auto ch: s) {
            if (current->children[ch - 'a'] == nullptr)
                current->children[ch - 'a'] = new TrieNode();
            
            current = current->children[ch - 'a'];

            current->suggestions.insert(s);
            if (current->suggestions.size() > 3)
                current->suggestions.erase(prev(current->suggestions.end(), 1));
        }
    }
    
    vector<vector<string>> search(string& searchWord) {
        vector<vector<string>> result;
        
        auto current = root;
        for (auto ch: searchWord) {
            if (current->children[ch - 'a'] == nullptr)
                break;
            
            current = current->children[ch - 'a'];
                        
            auto start = current->suggestions.begin();
            auto end = current->suggestions.end();
            result.push_back(vector<string>(start, end));
        }
        
        if (result.size() < searchWord.size()) {
            int n = searchWord.size() - result.size();
            for (int i = 0; i < n; i++)
                result.push_back({});
        }
        
        return result;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        
        Trie trie;
        for (auto product: products)
            trie.insert(product);
        
        return trie.search(searchWord);
    }
};

// TC: O(n*m*log(n))
// SC: O(sum(len(products[i])) * max(len(products[i])))