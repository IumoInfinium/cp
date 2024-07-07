for _ in range(int(input())):
    n,k=list(map(int,input().split(" ")))
    l=set(list(map(int,input().split(" "))))
    c=0
    while True:
        if c in l:
            c+=1
        else:
            if k>0:
                k-=1
                c+=1
            else:
                break
    print(c)
