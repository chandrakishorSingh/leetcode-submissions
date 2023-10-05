class Solution {
private:
    int mod = 1e9 + 7;
    
    int _countSubsetSum(int target, vector<vector<int>>& types, int n, vector<vector<int>>& store) {
        if (target == 0) {
            return 1;
        }
        
        if (n == 0) {
            return 0;
        }
        
        if (store[n][target] != -1) {
            return store[n][target];
        }
        
        int questionCount = types[n - 1][0];
        int questionMarks = types[n - 1][1];
        int result = 0;
        for (int i = 0; i <= questionCount; i++) {
            int totalMarks = i * questionMarks;
            
            if (totalMarks <= target) {
                result = (result + _countSubsetSum(target - totalMarks, types, n - 1, store)) % mod;
            }
        }
        
        store[n][target] = result;
        
        return store[n][target];
    }
    
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {        
        int n = types.size();
        vector<vector<int>> store(n + 1, vector<int>(target + 1, -1));
        
        return _countSubsetSum(target, types, n, store);
    }
};