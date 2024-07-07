for _ in range(int(input())):
    n,k=list(map(int,input().split(" ")))
    w=list(map(int,input().split(" ")))
    w.sort()
    if k<=n//2:
        c = abs(sum(w[:k])- sum(w[k:]))
    else:
        c= abs(sum(w[:n-k]-sum(w[n-k:])))
    print(c)