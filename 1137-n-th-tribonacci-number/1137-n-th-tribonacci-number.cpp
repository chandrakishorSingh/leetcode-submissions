class Solution {
public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        
        vector<int> values(n + 1);
        values[0] = 0;
        values[1] = 1;
        values[2] = 1;
        
        for (int i = 3; i <= n; i++)
            values[i] = values[i - 1] + values[i - 2] + values[i - 3];
        
        return values[n];
    }
};