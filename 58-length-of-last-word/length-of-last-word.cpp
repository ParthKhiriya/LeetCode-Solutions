class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = -1;
        int n = s.size();

        int end = n-1;
        while(s[end] == ' ') {
            end--;
        }

        for(int i=0; i<=end; i++) {
            if(s[i] == ' ') {
                index = i;
            }
        }

        return end - index;
    }
};