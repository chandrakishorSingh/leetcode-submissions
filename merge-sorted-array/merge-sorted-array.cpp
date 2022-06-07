class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m - 1; i >= 0; i--)
            nums1[i + n] = nums1[i];

        int p1 = n;
        int p2 = 0;
        int p = 0;
        while (p1 < m + n || p2 < n) {
            if (p1 == m + n) {
                nums1[p++] = nums2[p2++];
            } else if (p2 == n) {
                nums1[p++] = nums1[p1++];
            } else {
                if (nums1[p1] < nums2[p2]) {
                    nums1[p++] = nums1[p1++];
                } else {
                    nums1[p++] = nums2[p2++];
                }
            }
        }
    }
};
// TC: O(m + n)
// SC: O(1)