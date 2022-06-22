high = partitionIndex - 1;
}
return nums[targetIndex];
}
int partition(vector<int>& nums, int low, int high) {
int pivot = nums[low];
int left = low + 1;
int right = high;
while (left <= right) {
if (nums[left] <= pivot) {
left++;
} else {
swap(nums[left], nums[right]);
right--;
}
}
swap(nums[low], nums[left - 1]);
return left - 1;
}
};
​
// TC: O(n), on average
// SC: O(1)
```