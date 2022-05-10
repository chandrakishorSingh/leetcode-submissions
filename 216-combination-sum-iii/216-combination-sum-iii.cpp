class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        
        vector<int> currentSolution;
        dfs(n, k, 1, currentSolution, result);
        
        return result;
    }
    
    void dfs(int n, int k, int num, vector<int>& currentSolution, vector<vector<int>>& result) {
        if (n == 0 && k == 0) {
            result.push_back(currentSolution);
            return;
        }
        
        if (num == 10 || k == 0 || n < num)
            return;
        
        currentSolution.push_back(num);
        dfs(n - num, k - 1, num + 1, currentSolution, result);
        
        currentSolution.pop_back();
        dfs(n, k, num + 1, currentSolution, result);
    }
};