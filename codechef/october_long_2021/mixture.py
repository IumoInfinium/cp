t=int(input())
for _ in range(t):
    a,b = list(map(int,input().split(" ")))
    if (a>0 and b>0):
        print("Solution")
    elif (b==0):
        print("Solid")
    elif (a== 0):
        print("Liquid")