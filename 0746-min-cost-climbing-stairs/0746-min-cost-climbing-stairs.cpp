class Solution { 
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int lastState = 0;
        int secondLastState = 0;
        int result = lastState;
        for (int i = 1; i < n; i++) {
            result = min(cost[i] + lastState, cost[i - 1] + secondLastState);
            
            secondLastState = lastState;
            lastState = result;
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(1)