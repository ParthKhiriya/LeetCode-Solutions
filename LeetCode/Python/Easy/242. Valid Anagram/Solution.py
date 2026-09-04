class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        n = len(s)
        m = len(t)
        if n != m: 
            return False
        
        mpp = {}
        for i in range(n):
            mpp[s[i]] = mpp.get(s[i], 0) + 1
            mpp[t[i]] = mpp.get(t[i], 0) - 1
        
        for key, value in mpp.items():
            if value != 0:
                return False
        
        return True