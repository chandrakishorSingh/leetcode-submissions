class Solution:
    def waysToReachTarget(self, target: int, types: List[List[int]]) -> int:
            MOD = 10**9 + 7
            dp = [0] * (target + 1)
            dp[0] = 1

            for count, marks in types:
                for j in range(target, -1, -1):
                    for k in range(1, count + 1):
                        if j - k * marks < 0:
                            break
                        dp[j] = (dp[j] + dp[j - k * marks]) % MOD

            return dp[target]