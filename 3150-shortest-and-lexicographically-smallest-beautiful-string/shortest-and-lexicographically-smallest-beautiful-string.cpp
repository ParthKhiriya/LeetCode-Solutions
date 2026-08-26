class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int n = s.size();
        int count = 0;
        int left = 0;
        
        for(int right=0; right<n; right++) {
            if(s[right] == '1') count++;

            while(left <= right && (count > k || (count == k && s[left] == '0'))) {
                if(s[left] == '1') count--;
                left++;
            }

            if(count == k) {
                string curr = s.substr(left, right-left+1);

                if(ans == "" || curr.length() < ans.length() || (curr.length() == ans.length() && curr < ans)) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};