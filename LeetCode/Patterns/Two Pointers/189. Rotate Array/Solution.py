class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        temp = [0] * n

        for i in range(n):
            newIndex = (i+k) % n
            temp[newIndex] = nums[i]
        
        nums[:] = temp
        