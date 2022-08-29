result = result | (1 << i);
} else {
result = result & ~(1 << i);
}
}
return result;
}
};
​
// TC: O(2^n)
// SC: O(1), except the output
```
​
Solution 2:
​
- Using the "mirror" property of gray code here to write the recursive code.
- It's easy to see why this property ensures that the consecutive numbers will differ by exactly one bit.
- We start with {0, 1} which ensures the property. Then we "mirror" the numbers and add a '1' at the beginning to those new numbers. Now it's easy to see that all of these newly added numbers are different from the existing numbers from which they have been derived. Also, the it's easy to see that the first number of "mirror" numbers differs by the last number of previous series by exactly one bit. And since rest of the numbers(in order) of "mirror" sequence were already differing by one bit, they are maintaining the gray code property.
- Note that if we circularly shift the sequence then also we get a valid gray code sequence.
​
```
class Solution {
public:
vector<int> grayCode(int n) {
if (n == 1)
return {0, 1};
auto result = grayCode(n - 1);
int size = result.size();
for (int i = size - 1; i >= 0; i--) {
auto num = result[i];
num = num | (1 << (n - 1));
result.push_back(num);
}
return result;
}
};
​
// TC: O(2^n)
// SC: O(n), except the output
```