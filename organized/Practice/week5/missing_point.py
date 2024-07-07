for _ in range(int(input())):
    n=int(input())
    dx={}
    dy={}
    for i in range((4*n)-1):
        x,y=map(int,input().split(" "))
        dx[x]=dx.get(x,0)+1
        dy[y]=dy.get(y,0)+1
    for k,v in dx.items():
        if(v%2!=0):
            x=k
            break
    for k,v in dy.items():
        if(v%2!=0):
            y=k
            break
    print(x,y)
        