t=int(input())
for _ in range(t):
    x,k= list(map(int,input().split(" ")))
    print(f"{x*2} {(x*k*((x*k)-1))}")