for tt in range(int(input())):
    n=int(input())
    a=list(map(int,input().split(" ")))
    s=-1
    for i in range(n):
        if a[i] == 2 and a[i]>=a[s]:
            s=i
        elif a[i] == 2:
            s=i

    t1,t2=0,0
    for i in range(0,n,2):
        t1+=a[i]
    for i in range(1,n,2):
        t2+=a[i]
    if s>-1:
        l=[a[s],t1,t2]
        l.sort()
        print(l[-1])
    else:
        if(t2>t1):
            print(t2)
        else:
            print(t1)