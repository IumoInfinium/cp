n=int(input())
l={}
last=""
for i in range(n):
    x=input()
    if last!="":
        if last[-1] != x[0]:
            f=0
    else:
        if x in l.keys():
            f=0
        else:
            l[x]=1
            last=x
            f=1

if f:
    print("Yes")
else:
    print("No")