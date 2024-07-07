for _ in range(int(input())):
    n,m=list(map(int,input().split(" ")))
    m=[]
    for i in range(n):
        l=list(map(int,input().split(" ")))
        m.append(max(l)-min(l))
    print(max(m))