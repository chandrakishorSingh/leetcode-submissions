class Solution {
private:
    int _deleteAndEarn(vector<pair<int, int>>& items, vector<int>& store) {
        int n = items.size();
        
        for (int i = 1; i < n; i++) {
            if (items[i].first - items[i - 1].first == 1) {
                store[i + 1] = max(store[i], store[i - 1] + items[i].first * items[i].second);
            } else {
                store[i + 1] = store[i] + items[i].first * items[i].second;
            }
        }
        
        return store[n];
    }
    
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        map<int, int> count;
        
        for (int i = 0; i < n; i++)
            count[nums[i]]++;
        
        vector<pair<int, int>> items;
        for (auto it = count.begin(); it != count.end(); it++)
            items.push_back(*it);
        
        vector<int> store(items.size() + 1);
        store[1] = items[0].first * items[0].second;
        
        return _deleteAndEarn(items, store);
        
        return 0;
    }
};

// TC: O(n)
// SC: O(n)