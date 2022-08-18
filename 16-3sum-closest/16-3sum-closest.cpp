class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            if (result == target)
                break;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            auto closestSum = twoSum(target - nums[i], i + 1, nums, result);
            if (abs(result - target) > abs(nums[i] + closestSum - target))
                result = nums[i] + closestSum;
        }

        return result;
    }

    int twoSum(int target, int startIndex, vector<int>& nums, int& result) {
        int left = startIndex;
        int right = nums.size() - 1;

        int closestSum = nums[left] + nums[right];
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                return target;
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }

            if (abs(sum - target) < abs(closestSum - target))
                closestSum = sum;
        }

        return closestSum;
    }
};