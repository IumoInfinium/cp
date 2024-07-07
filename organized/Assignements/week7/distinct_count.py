for _ in range(int(input())):
    n,k=list(map(int,input().split()))
    a=list(map(int,input().split()))
    d={}
    c=0
    for i in range(k):
        if a[i] in d.keys():
            d[a[i]]+=1
        else:
            d[a[i]]=1
            c+=1
    print(c,end=' ')
    for i in range(0,n-k):
        if d[a[i]]==1:
            del d[a[i]]
            c-=1
        else:
            d[a[i]]-=1
            
        if a[i+k] in d.keys():
            d[a[i+k]]+=1
        else:
            d[a[i+k]]=1
            c+=1
        print(c,end=' ')
    print()