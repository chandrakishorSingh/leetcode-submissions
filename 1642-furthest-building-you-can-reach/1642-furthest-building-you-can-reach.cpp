class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        
        int n = heights.size();
        int it = 1;
        while (it < n) {
            while (it < n) {
                int heightDifference = heights[it] - heights[it - 1];
                if (heightDifference <= 0) {
                    it++;
                } else if (bricks >= heightDifference) {
                    bricks -= heightDifference;
                    pq.push(heightDifference);
                    it++;
                } else {
                    break;
                }
            }
            
            if (ladders == 0 || it == n)
                break;
            
            int heightDifference = heights[it] - heights[it - 1];
            if (pq.empty() || heightDifference > pq.top()) {
                it++;
            } else {
                auto top = pq.top();
                pq.pop();
                
                bricks += top;
            }
            
            ladders--;
        }
        
        return it - 1;
    }
};

// TC: O(2^n)
// SC: O(n)
// n = len(heights)
