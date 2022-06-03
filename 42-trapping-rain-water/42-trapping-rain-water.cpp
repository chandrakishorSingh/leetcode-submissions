class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> maxFromLeft(n);
        vector<int> maxFromRight(n);
        
        for (int i = 1; i < n; i++)
            maxFromLeft[i] = max(maxFromLeft[i - 1], height[i - 1]);
        
        for (int i = n - 2; i >= 0; i--)
            maxFromRight[i] = max(maxFromRight[i + 1], height[i + 1]);
        
        int result = 0;
        for (int i = 1; i < n - 1; i++)
            if (min(maxFromLeft[i], maxFromRight[i]) > height[i])
                result += min(maxFromLeft[i], maxFromRight[i]) - height[i];
        
        return result;
    }
};