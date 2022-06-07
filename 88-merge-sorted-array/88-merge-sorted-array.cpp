class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m - 1, j = 0; i >= 0; i--, j++)
            nums1[m + n - 1 - j] = nums1[i];
        
        int j = n;
        int k = 0;
        for (int i = 0; i < m + n; i++) {
            if (k == n)
                nums1[i] = nums1[j++];
            else if (j == m + n)
                nums1[i] = nums2[k++];
            else
                nums1[i] = (nums1[j] < nums2[k]) ? nums1[j++] : nums2[k++];
        }
    }
};