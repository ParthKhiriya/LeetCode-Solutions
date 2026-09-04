class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        n = len(password)
        if n < 8: 
            return False

        lowercase = False
        uppercase = False
        digit = False
        special = False

        for i in range(n):
            c = password[i]

            if i != 0 and password[i-1] == c:
                return False

            if c >= 'a' and c <= 'z':
                lowercase = True
            elif c >= 'A' and c <= 'Z':
                uppercase = True
            elif c >= '0' and c <= '9':
                digit = True
            elif c == '!' or c == '@' or c == '#' or c == '$' or c == '%' or c == '^' or c == '&' or c == '*' or c == '(' or c == ')' or c == '-' or c == '+' :
                special = True
            
        return lowercase and uppercase and digit and special