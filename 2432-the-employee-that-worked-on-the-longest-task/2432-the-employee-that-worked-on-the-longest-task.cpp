class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int result = n + 1;
        
        int previousEndTime = 0;
        int longestTaskTime = 0;
        for (auto& log: logs) {
            auto taskTime = log[1] - previousEndTime;
            
            if (taskTime > longestTaskTime) {
                longestTaskTime = taskTime;
                result = log[0];
            } else if (taskTime == longestTaskTime) {
                longestTaskTime = taskTime;
                result = min(result, log[0]);
            }
            
            previousEndTime = log[1];
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(1)