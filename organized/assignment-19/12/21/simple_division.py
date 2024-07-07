for tt in range(int(input())):
    n,x,y=list(map(int,input().split(" ")))
    a=list(map(int,input().split(" ")))
    c=0
    for i in a:
        if(i<=x and i%y==0):
            c+=1
    print(c)