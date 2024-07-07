for _ in range(int(input())):
    n=int(input())
    d={}
    for i in range(3*n):
        s,c=input().split(" ")
        c=int(c)
        if s in d.keys():
            d[f'{s}']+=c
        else:
            d[f'{s}']=c
    d=sorted(d.items(),key=lambda x:x[1])
    for i in range(len(d)):
        print(d[i][1],end=" ")
    print()