}
return true;
}
};
​
/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/
​
// TC:
// Trie()               -> O(1)
// insert(word)         -> O(len(word))
// search(word)         -> O(len(word))
// startsWith(prefix)   -> O(len(prefix))
​
// SC:
// Trie()               -> O(1)
// insert(word)         -> O(len(word))
// search(word)         -> O(1)
// startsWith(prefix)   -> O(1)
```