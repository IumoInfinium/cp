class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        l = s.split()
        l = [i for i in l]
        l.reverse()
        s = ""
        for i in l:
            x= i.strip() 
            if (x == ""):
                continue
            else:
                s += i + " "
        return s.strip()
