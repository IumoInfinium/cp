from collections import defaultdict
try:
    from fractions import gcd
except:
    from math import gcd
    
t=int(input())
for _ in range(t):
    x=int(input())
    lines=defaultdict(set)
    for i in range(x):
        a,b,c=map(int,input().strip().split(" "))
        g=gcd(a,b)
        h=gcd(g,c)
        lines[a/g,b/g].add((a/h,b/h,c/h))
    print(max(map(len,lines.values())))