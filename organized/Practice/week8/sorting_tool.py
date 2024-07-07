n,m=map(int,input().split())
l=list(map(int,input().split()))
d={}
for i in l:
    d[i]=l.count(i)
l=[(i,j) for i,j in d.items()]
l.sort(key=lambda x:x[1],reverse=True)
for i,j in l:
    print((str(i)+" ")*j,end="")
print()