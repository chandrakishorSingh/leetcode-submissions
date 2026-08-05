class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lisLength(n);
        vector<int> lisCount(n);

        int result = 0;
        int currentLisLength = 0;
        for (int i = 0; i < n; i++) {
            int length = 0;
            int count = 0;

            for (int j = 0; j < i; j++) {
                // cout << "nums[j]" << nums[j] << " nums[i]" << nums[i] << endl;
                if (nums[j] < nums[i]) {
                    // cout << "hello" << endl;
                    if (length < lisLength[j]) {
                        length = lisLength[j];
                        count = lisCount[j];
                    } else if (length == lisLength[j]) {
                        count += lisCount[j];
                    }
                }

                // cout << "i = " << i << " j = " << j << " length = " << length << " count = " << count << endl;
            }

            lisLength[i] = length + 1;
            lisCount[i] = length == 0 ? 1 : count;

            // cout << "i = " << i << " len = " << lisLength[i] << " count = " << lisCount[i] << endl;

            if (currentLisLength < lisLength[i]) {
                currentLisLength = lisLength[i];
                result = lisCount[i];
            } else if (currentLisLength == lisLength[i]) {
                result += lisCount[i];
            }
        }

        return result;
    }
};