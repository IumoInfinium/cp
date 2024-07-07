from collections import deque
def solve(mulset,q,maxq):
    res=[]
    q1 = deque(sorted(mulset,reverse=True))
    q2 = deque()
    for i in range(1,maxq+1):
        if(not q2 or q1[0]>q2[0]): ele=q1.popleft()
        else: ele=q2.popleft()

        if i in q:
            res.append(ele)
        ele=ele>>1
        if(ele>0): q2.append(ele)
        if not q1: q1,q2=q2,q1
    print("\n".join(map(str,res)))

n,m=map(int,input().split())
mulset=list(map(int,input().split()))
q=[int(input()) for _ in range(m)]
maxq=q[-1]
solve(mulset,set(q),maxq)