class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        
        int result;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canFinishEating(piles, mid, h)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
    
    bool canFinishEating(vector<int>& piles, int speed, int hours) {
        for (auto bananas: piles) {
            int hourReq = ((long long)bananas + speed - 1) / speed;
            
            hours -= hourReq;
            if (hours < 0)
                return false;
        }
        
        return true;
    }
};