a,b,c=list(map(int,input().split(" ")))
la=[]
lb=[]
for i in range(a):
    la.append(int(input()))
for i in range(b):
    lb.append(int(input()))
l=la+lb
l.sort()
for i in range(c):
    s=int(input())
    l.append(s)
    l.sort()
    x=1
    while(x):
        if l.index(s)==0:
            

