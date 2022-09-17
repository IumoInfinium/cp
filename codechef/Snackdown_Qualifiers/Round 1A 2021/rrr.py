t=int(input())
for _ in range(t):
    n,k = list(map(int,input().split(" ")))
    print(
        n*(n-1)//2-((n-k)*(n*k-1)//2)//k
    )