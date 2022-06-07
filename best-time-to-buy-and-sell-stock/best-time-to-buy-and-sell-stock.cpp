class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxSellingPrice = prices[n - 1];

        int result = 0;
        for (int i = n - 2; i >= 0; i--) {
            result = max(result, maxSellingPrice - prices[i]);
            maxSellingPrice = max(maxSellingPrice, prices[i]);
        }

        return result;
    }
};

// TC: O(n)
// SC: O(1)