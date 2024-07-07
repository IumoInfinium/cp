t=int(input())
for _ in range(t):
    x,y = input().split(" ")
    x,y= int(x),int(y)
    count=0
    while(x!=y):
        if(x == y):
            break
        if(x<y):
            x= x+2
            count+=1
        elif x>y:
            x=x-1
            count+=1
    print(count)