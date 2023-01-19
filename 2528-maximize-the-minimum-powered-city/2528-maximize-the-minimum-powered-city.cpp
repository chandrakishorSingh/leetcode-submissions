class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        
        vector<long long> power(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += stations[i];
            
            if (i >= r) {
                sum -= (i >= (2 * r + 1)) ? stations[i - (2 * r + 1)] : 0;
                power[i - r] = sum;
            }
        }
        for (int i = n - r; i < n; i++) {
            sum -= i > r ? stations[i - r - 1] : 0;
            power[i] = sum;
        }
        
        long long low = *min_element(power.begin(), power.end());
        long long high = *max_element(power.begin(), power.end()) + k;
        
        long long result = low;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (canSupply(power, mid, r, k)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return result;
    }
    
    bool canSupply(vector<long long>& power, long long requiredPower, int r, int k) {
        queue<pair<int, int>> que;
        
        long long additionalPower = 0;
        for (int i = 0; i < power.size(); i++) {
            if (!que.empty() && i == que.front().first) {
                additionalPower += que.front().second;
                que.pop();
            }
            
            if (power[i] + additionalPower >= requiredPower)
                continue;
            
            long long diff = requiredPower - power[i] - additionalPower;
            if (diff > k)
                return false;
            
            k -= diff;
            additionalPower += diff;
            que.push({ i + (2 * r + 1), -diff });
        }
        
        return true;
    }
};

// TC: O(n * log(sum(stations) + k - min(stations)))
// SC: O(n)