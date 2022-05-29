class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();

        vector<int> mask(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < words[i].size(); j++)
                mask[i] |= 1 << (words[i][j] - 'a');

        int result = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (!(mask[i] & mask[j]))
                    result = max(result, (int)words[i].size() * (int)words[j].size());

        return result;
    }
};

// TC: O(n^2 + sum(len(words[i])))
// SC: O(n)