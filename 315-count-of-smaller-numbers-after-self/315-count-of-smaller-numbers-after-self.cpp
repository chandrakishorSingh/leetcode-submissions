class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> numberToIndex(n);
        for (int i = 0; i < n; i++)
            numberToIndex[i] = {nums[i], i};
        
        vector<int> result(n);
        
        sort(numberToIndex, result);
        
        return result;
    }
    
    void sort(vector<pair<int, int>>& numberToIndex, vector<int>& result) {
        int n = numberToIndex.size();
        vector<pair<int, int>> aux(n);
        sort(numberToIndex, 0, n - 1, aux, result);
    }
    
    void sort(vector<pair<int, int>>& numberToIndex, int start, int end, vector<pair<int, int>>& aux, vector<int>& result) {
        if (start == end) {
            return;
        }
        
        int mid = start + (end - start) / 2;
        
        sort(numberToIndex, start, mid, aux, result);
        sort(numberToIndex, mid + 1, end, aux, result);
        
        merge(numberToIndex, start, mid, end, aux, result);
    }
    
    void merge(vector<pair<int, int>>& numberToIndex, int start, int mid, int end, vector<pair<int, int>>& aux, vector<int>& result) {
        for (int i = start; i <= end; i++)
            aux[i] = numberToIndex[i];
        
        int it1 = start;
        int it2 = mid + 1;
        int lessCount = 0;
        for (int i = start; i <= end; i++) {
            if (it1 > mid) {
                numberToIndex[i] = aux[it2++];
            } else if (it2 > end) {
                result[aux[it1].second] += lessCount;
                numberToIndex[i] = aux[it1++];
            } else if (aux[it1].first > aux[it2].first) {
                numberToIndex[i] = aux[it2++];
                lessCount++;
            } else {
                result[aux[it1].second] += lessCount;
                numberToIndex[i] = aux[it1++];
            }
        }
    }
};

// TC: O(n * log(n))
// SC: O(n)