}
if (result.size() < searchWord.size()) {
int n = searchWord.size() - result.size();
for (int i = 0; i < n; i++)
result.push_back({});
}
return result;
}
};
​
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
​
// TC: O(n*m*log(n))
// SC: O(sum(len(products[i])) * max(len(products[i])))
```