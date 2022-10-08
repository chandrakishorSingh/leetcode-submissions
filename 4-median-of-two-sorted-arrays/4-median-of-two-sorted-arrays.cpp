class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        for (auto num: nums1)
            arr.push_back(num);
        
        for (auto num: nums2)
            arr.push_back(num);
        
        sort(arr.begin(), arr.end());
        
        int middleIndex = arr.size() / 2;
        return arr.size() % 2 == 0 ? (arr[middleIndex] + arr[middleIndex - 1]) / 2.0 : arr[middleIndex];
    }
};
// TC: O((m + n) * log(m + n))
// SC: O(m + n)