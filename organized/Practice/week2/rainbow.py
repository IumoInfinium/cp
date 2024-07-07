st=[1,2,3,4,5,6,7]
for tt in range(int(input())):
    n=int(input())
    l=list(map(int,input().split(" ")))
    f=0
    for i in range(n//2+1):
        if l[i]==l[-(i+1)] and l[i] in st:
            f=1
        else:
            f=0
            break
    if(f==1):
        print("yes")
    else:
        print("no")