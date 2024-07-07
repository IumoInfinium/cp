for _ in range(int(input())):
    n=int(input())
    d=[]
    f=0
    l= list(map(int,input().split(" ")))
    for s in l :
        print(d)
        if d==[]:
            d.append(s)
        else:
            le=len(d)
            for i in range(le):
                if d[i]>s:
                    d[i]=s
                    f=1
                    break
            if f==0:
                d.append(s)
    print(d)