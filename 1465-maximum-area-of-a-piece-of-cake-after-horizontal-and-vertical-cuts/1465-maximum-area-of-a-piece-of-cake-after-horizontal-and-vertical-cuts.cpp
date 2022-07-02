class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        
        int maxHorizontalCut = h - horizontalCuts[n - 1];
        for (int i = 0, prev = 0; i < n; i++) {
            maxHorizontalCut = max(maxHorizontalCut, horizontalCuts[i] - prev);
            prev = horizontalCuts[i];
        }
        
        int maxVerticalCut = w - verticalCuts[m - 1];
        for (int i = 0, prev = 0; i < m; i++) {
            maxVerticalCut = max(maxVerticalCut, verticalCuts[i] - prev);
            prev = verticalCuts[i];
        }
        
        int mod = 1e9 + 7;
        return ((int64_t)maxHorizontalCut * (int64_t)maxVerticalCut) % mod;
    }
};