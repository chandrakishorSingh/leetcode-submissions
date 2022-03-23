class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int size = pow(2, 11);
        
        int maxPoints = 0;
        int mask = -1;
        for (int i = 0; i < size; i++) {
            int points = 0;
            int arrowsLeft = numArrows;
            for (int j = 0; j < 11; j++) {
                if ((1 << j) & i) {
                    points += j + 1;
                    arrowsLeft -= aliceArrows[j + 1] + 1;
                    
                    if (arrowsLeft < 0)
                        break;
                }
            }
            
            if (arrowsLeft >= 0 && maxPoints < points) {
                maxPoints = points;
                mask = i;
            }
        }
        
        vector<int> result = {0};
        for (int i = 0; i < 11; i++) {
            if ((1 << i) & mask) {
                result.push_back(aliceArrows[i + 1] + 1);
            } else {
                result.push_back(0);
            }
        }
        
        int remainingArrows = numArrows - accumulate(result.begin(), result.end(), 0);
        result[0] = remainingArrows;
        
        return result;
    }
};