class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        vector<vector<int>> numberToIndices(k + 1, vector<int>());

        for (int i = 0; i < rolls.size(); i++)
            numberToIndices[rolls[i]].push_back(i);
        
        int result = 0;
        int startIndex = 0;
        bool flag = true;
        while (flag) {
            result++;
            
            int maxStartIndex = startIndex;
            for (int i = 1; i <= k; i++) {
                auto newStartIndex = binarySearch(startIndex, numberToIndices[i]);

                if (newStartIndex == -1) {
                    flag = false;
                    break;
                }
                
                maxStartIndex = max(maxStartIndex, newStartIndex);
            }
            
            startIndex = maxStartIndex + 1;
        }
        
        return result;
    }
    
    int binarySearch(int target, vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] < target) {
                low = mid + 1;
            } else {
                result = arr[mid];
                high = mid - 1;
            }
        }
        
        return result;
    }
};

// TC: O(k^(n/k) * log(n))
// SC: O(k^(n/k))