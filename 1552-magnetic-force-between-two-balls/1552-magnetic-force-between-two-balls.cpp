class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int n = position.size();
        int minGap = INT_MAX;
        for (int i = 1; i < n; i++)
            minGap = min(minGap, position[i] - position[i - 1]);
        
        int low = minGap;
        int high = position.back() - position.front();
        int result = minGap;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canPlace(mid, position, m)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return result;
    }
    
    bool canPlace(int gap, vector<int>& position, int m) {
        int prev = position[0];
        m--;
        
        for (int i = 1; i < position.size() && m > 0; i++) {
            if (position[i] - prev >= gap) {
                prev = position[i];
                m--;
            }
        }
        
        return m == 0;
    }
};

// TC: O(n * log(n))
// SC: O(sort function)