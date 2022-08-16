class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        
        vector<int64_t> scores(n);
        for (int i = 0; i < n; i++)
            scores[edges[i]] += i;
        
        return max_element(scores.begin(), scores.end()) - scores.begin();
    }
};

// TC: O(n)
// SC: O(n)