class Solution {
private:
    int _deleteAndEarn(int index, vector<pair<int, int>>& items, vector<int>& store) {
        // cout << "index = " << index << " ";
        if (index == 0) {
            // cout << 0 << endl;
        cout << "index = " << index << " " << 0 << endl;
            
            return 0;
        }
        
        if (index == 1) {
            // cout << items[index - 1] << endl;
        cout << "index = " << index << " " << items[index - 1].first * items[index - 1].second << endl;
            
            return items[index - 1].first * items[index - 1].second;
        }
        
        if (store[index] != -1) {
            // cout << store[index] << endl;
        cout << "index = " << index << " " << store[index] << endl;
            
            return store[index];
        }
        
        if (items[index - 1].first - items[index - 2].first == 1) {
            store[index] = max(
                _deleteAndEarn(index - 1, items, store),
                _deleteAndEarn(index - 2, items, store) + items[index - 1].first * items[index - 1].second
            );
        } else {
            store[index] = _deleteAndEarn(index - 1, items, store) + items[index - 1].first * items[index - 1].second;
        }
        
                cout << "index = " << index << " " << store[index] << endl;

        
        return store[index];
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
        
        vector<int> store(items.size() + 1, -1);
        // for (auto num: items) {
        //     cout << num << endl;
        // }
        
        return _deleteAndEarn(items.size(), items, store);
        
        return 0;
    }
};