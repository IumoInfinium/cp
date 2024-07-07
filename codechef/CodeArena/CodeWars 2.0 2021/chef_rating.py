t=int(input())
for tt in range(t):
    n=int(input())
    l=list(map(int,input().split(" ")))
    l.sort(reverse=True)
    print('sort desc -',l)
    l.sort()
    print('sorted asc-',l)