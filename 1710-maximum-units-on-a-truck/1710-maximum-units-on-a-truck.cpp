class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        
        sort(boxTypes.rbegin(), boxTypes.rend(), [](vector<int>& box1, vector<int>& box2) {
            return box1[1] < box2[1];
        });
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (truckSize < boxTypes[i][0]) {
                result += boxTypes[i][1] * truckSize;
                break;
            }
            
            result += boxTypes[i][0] * boxTypes[i][1];
            truckSize -= boxTypes[i][0];
        }
        
        return result;
    }
};