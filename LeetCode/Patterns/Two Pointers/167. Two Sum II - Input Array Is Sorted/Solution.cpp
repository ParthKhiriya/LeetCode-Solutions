class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int left = 0;
        int right = n-1;

        while(left < right) {
            int l = numbers[left];
            int r = numbers[right];
            if(l + r == target) return {left+1, right+1};
            else if(l + r > target) right--;
            else left++;
        }

        return {-1, -1};
    }
};