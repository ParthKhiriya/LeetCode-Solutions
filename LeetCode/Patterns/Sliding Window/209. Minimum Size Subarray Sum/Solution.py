class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        minLen = float('inf')

        currentSum = 0
        left = 0

        for right in range(n):
            currentSum += nums[right]

            while currentSum >= target:
                minLen = min(minLen, right - left + 1)
                currentSum -= nums[left]
                left += 1
        
        return minLen if minLen != float('inf') else 0

        