def solve(start, end):
    S,E =start,end
    res=E
    while start<=end:
        mid=(start+end)//2
        if mid==0:
            ctz=ntz[E]
            cto=nto[E]
        else:
            ctz=ntz[E]-ntz[mid-1]
            cto = nto[E]-nto[mid-1]
        if ctz<=k and cto<=k:
            res=mid
            end=mid-1
        else:
            start=mid+1
    return res

def solved(low,high):
    L,R=low,high
    res=L
    while low<=high:
        mid=(low+high)//2
        if retry[mid]<=L:
            low=mid+1
            res=mid
        else:
            high=mid-1
    return res

for _ in range(int(input())):
    n, k, q = map(int, input().split())
    string = input()
    ntz = [0]*(n)
    nto = [0]*(n)
    for i in range(n):
        if i == 0:
            ntz[0] = int('0' == string[i])
            nto[0] = int('1' == string[i])
        else:
            ntz[i] = ntz[i-1] + int('0' == string[i])
            nto[i] = nto[i-1] + int('1' == string[i])

    res = [0]*(n)
    retry = [0]*(n)
    for i in range(n):
        temp = solve(0, i)
        retry[i] = temp
        res[i] = i-temp+1

    reans = [res[0]]
    for i in range(1, n):
        temp = res[i]+reans[i-1]
        reans.append(temp)

    for _ in range(q):
        l, r = map(int, input().split())
        l-=1
        r-=1
        ind = solved(l, r)
        fa = reans[r]-reans[ind]
        val = ind-l+1
        fa += val*(val+1)//2
        print(fa)
