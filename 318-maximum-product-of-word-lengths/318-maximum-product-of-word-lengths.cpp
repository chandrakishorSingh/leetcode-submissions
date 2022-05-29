class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();

        unordered_map<int, int> maskToLength;
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < words[i].size(); j++)
                mask |= 1 << (words[i][j] - 'a');
            
            maskToLength[mask] = max(maskToLength[mask], (int)words[i].size());
        }

        int result = 0;
        for (auto mask1: maskToLength)
            for (auto mask2: maskToLength)
                if (!(mask1.first & mask2.first))
                    result = max(result, (int)mask1.second * (int)mask2.second);

        return result;
    }
};

// TC: O(n^2 + sum(len(words[i])))
// SC: O(n)