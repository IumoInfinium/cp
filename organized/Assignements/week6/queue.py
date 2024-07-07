n,q=map(int,input().split(' '))
d=list(map(int,input().split(' ')))
for _ in range(q):
    c=0
    l,r,x=map(int,input().split(' '))
    for i in range(l-1,r):
        if d[i]>=x:
            c+=1
    print(c)