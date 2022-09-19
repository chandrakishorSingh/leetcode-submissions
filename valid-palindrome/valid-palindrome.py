class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        s = list(filter(lambda x: x.isalnum(), list(s)))
        
        return s == s[::-1]
        