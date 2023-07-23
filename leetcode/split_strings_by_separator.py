class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        l = []
        for x in words:
            tmp = x.split(separator)
            for t in tmp:
                if(t != ""):
                    l.append(t)
        
        return l
        
