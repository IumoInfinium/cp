for _ in range(int(input())):
    n,q = map(int,input().split())
    ls = [0]+list(map(int,input().split()))
    Q = [[int(input()),i] for i in range(q)]
    ls.sort()
    Q.sort()
    cur = 0; prev = 0; prefix = 0; i = 1
    ans = [0]*q
    while cur<q:
        tmp = Q[cur][0]
        while i<=n and ls[i]<tmp:
            prefix += (tmp-ls[i])
            i += 1
        i -= 1
        while prefix>prev:
            prev += 1
            prefix -= (tmp-ls[prev])
        ans[Q[cur][1]] = n-prev
        if cur<q-1:
            prefix += (i-prev)*(Q[cur+1][0]-tmp)
        i += 1
        cur += 1
    print(*ans,sep='\n')