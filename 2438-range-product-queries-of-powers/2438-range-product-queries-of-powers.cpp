class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers = getPowers(n);
        
        vector<int> result(queries.size());
        int mod = 1e9 + 7;
        for (int i = 0; i < queries.size(); i++) {
            result[i] = evaluateQuery(powers, queries[i][0], queries[i][1]);
        }
        
        return result;
    }
    
    vector<int> getPowers(int n) {
        vector<int> result;
        
        int weight = 1;
        while (n != 0) {
            int flag = n & 1;
            if (flag)
                result.push_back(weight);
            
            weight = weight << 1;
            n = n >> 1;
        }
        
        return result;
    }
    
    int evaluateQuery(vector<int>& powers, int left, int right) {
        int mod = 1e9 + 7;
        
        int64_t result = 1;
        for (int i = left; i <= right; i++) {
            result = (result * powers[i]) % mod;
        }
        
        return result;
    }
};