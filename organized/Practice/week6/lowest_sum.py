for _ in range(int(input())):
    n,k=map(int,input().split())
    l1=list (map(int,input().split()))
    l1.sort()
    l2=list (map(int,input().split()))
    l2.sort()
    d=[]
    for i in range (min(n,10001)):
        nn=min(n,10001//(i+1))
        for j in range(nn):
            d.append(l2[i]+l1[j])
    d.sort()
    for i in range(k):
        q=int(input())
        print (d[q-1])