class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)

        left = 0
        right = n-1

        while left < right:
            l = numbers[left]
            r = numbers[right]

            if l + r == target:
                return [left+1, right+1]
            elif l + r < target:
                left += 1
            else:
                right -= 1
        
        return [-1, -1]