class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if (stockPrices.size() <= 2)
            return stockPrices.size() - 1;
        
        sort(stockPrices.begin(), stockPrices.end(), [](vector<int>& point1, vector<int>& point2){
            return point1[0] - point2[0] < 0;
        });
        
        int result = 1;
        for (int i = 2; i < stockPrices.size(); i++) {
            if (!isSlopesEqual(stockPrices[i], stockPrices[i - 1], stockPrices[i - 2]))
                result++;
        }
        
        return result;
        
    }
    
    bool isSlopesEqual(vector<int>& point1, vector<int>& point2, vector<int>& point3) {
        return (int64_t)(point2[1] - point1[1]) * (point3[0] - point2[0]) == (int64_t)(point3[1] - point2[1]) * (point2[0] - point1[0]);
    }
};