class Solution:
    def countDigits(self, num: int) -> int:
        return sum(num % int(digit) == 0 for digit in str(num))