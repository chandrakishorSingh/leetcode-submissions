class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        
        int maxHorizontalCut = max(horizontalCuts[0], h - horizontalCuts[n - 1]);
        for (int i = 1; i < n; i++)
            maxHorizontalCut = max(maxHorizontalCut, horizontalCuts[i] - horizontalCuts[i - 1]);
        
        int maxVerticalCut = max(verticalCuts[0], w - verticalCuts[m - 1]);
        for (int i = 1; i < m; i++)
            maxVerticalCut = max(maxVerticalCut, verticalCuts[i] - verticalCuts[i - 1]);
        
        int mod = 1e9 + 7;
        return ((int64_t)maxHorizontalCut * (int64_t)maxVerticalCut) % mod;
    }
};

// TC: O(k * log(k))
// SC: O(1)
// k = max(len(verticalCuts), len(horizontalCuts))