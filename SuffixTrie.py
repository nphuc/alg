class SuffixTrie(object):
    def __init__(self,t):
        t+="$"
        self.root={}
        for i in range(len(t)):
            cur=self.root
            for c in t[i:]:
                if c not in cur:
                    cur[c]={}
                cur=cur[c]
    def followPath(self,s):
        cur=self.root
        for c in s:
            if c not in cur:
                return None
            cur=cur[c]
        return cur
    def hasSubString(self,s):
        return self.followPath(s) is not None
    def hasSuffix(self,s):
        none=self.followPath(s)
        return none is not None and "$" in node
sft=SuffixTrie("abaaba")
"""
how many nodes SuffixTrie Have?
    linear t="aaaaaaaaaaa" =(a^m)
    ->2m+1 node
    a^n b^n -> n2+4n+2

"""
