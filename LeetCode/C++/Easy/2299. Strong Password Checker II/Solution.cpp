class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        if(n < 8) return false;

        bool lowercase = false;
        bool uppercase = false;
        bool digit = false;
        bool special = false;
        bool adjacentSame = true;

        for(int i=0; i<n; i++) {
            char c = password[i];

            if(c > 'a' && c < 'z') {
                lowercase = true;
            } else if (c > 'A' && c < 'Z') {
                uppercase = true;
            } else if (c >= '0' && c < '9') {
                digit = true;
            } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '+') {
                special = true;
            }

            if(i > 0 && password[i-1] == c) {
                adjacentSame = false;
            }
        }

        return (lowercase && uppercase && digit && special && adjacentSame);
    }
};