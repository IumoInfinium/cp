for tt in range(int(input())):
    v=list(map(int,input().split(" ")))
    l = list(map(int,input().split(" ")))
    count=0
    for i in range(v[1]):
        if l[i]==1:
            count+=v[3]
        else:
            count+=v[2]
    print(count)