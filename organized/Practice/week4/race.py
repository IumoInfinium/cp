for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split(" ")))
    l.sort()
    c=l[1]-l[0]
    for i in range(2,n):
        if l[i]-l[i-1]<c:
            c=l[i]-l[i-1]
    print(c)