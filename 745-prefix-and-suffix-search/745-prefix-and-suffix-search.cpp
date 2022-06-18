class TrieNode {
public:
    bool isEnd;
    int index;
    vector<TrieNode*> children;
    
    TrieNode(bool isEnd=false, int index=-1) {
        this->isEnd = isEnd;
        this->index = index;
        this->children.resize(27, nullptr);
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        this->root = new TrieNode();
    }
    
    void insert(string& s, int index) {
        auto current = root;
        for (auto ch: s) {
            if (current->children[ch - 'a'] == nullptr)
                current->children[ch - 'a'] = new TrieNode();
            
            current = current->children[ch - 'a'];
            current->index = index;
        }
        
        current->isEnd = true;
        current->index = index;
    }
    
    int match(string& searchString) {
        int result = -1;
        
        auto current = root;
        for (auto ch: searchString) {
            if (current->children[ch - 'a'] == nullptr)
                return result;
            
            current = current->children[ch - 'a'];
        }
        
        return current->index;
    }
};



class WordFilter {
public:
    Trie trie;
    
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            auto reverseWord = string(words[i].rbegin(), words[i].rend());
            for (int j =  0; j < words[i].size(); j++) {
                auto entry = words[i].substr(j) + "{" + words[i];
                // cout << "w" << entry << endl;
                trie.insert(entry, i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        auto entry = suffix + "{" + prefix;
        // cout << "f" << entry << endl;
        
        return trie.match(entry);
    }
};

// TC: O(sum(len(words[i])) * q)
// SC: O(sum(len(words[i])))

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */