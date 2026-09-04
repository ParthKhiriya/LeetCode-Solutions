class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        xr = 0

        for num in nums:
            xr ^= num

        return xr