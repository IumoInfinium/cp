for tt in range(int(input())):
    v=list(map(int,input().split(" ")))
    l=list(map(int,input().split(" ")))
    f=0
    for i in range(v[1]):
        if l[i] != 1:
            f=1
            break
    nf=0
    for i in range(v[1],v[0]):
        if l[i]==0:
            nf=1
            break
    if f==0 and nf==0:
        print(100)
    elif f==1 and nf==0:
        print(0)
    elif f==0 and nf==1:
        print(v[2])
    elif f==1 and nf ==1:
        print(0)