t=int(input())
for ii in range(t):
    n=int(input())
    if(n==1):
        print(3)
    elif n==2:
        print(33)
    else:
        print(3,end="")
        for i in range(n-2):
            print(0,end="")
        print(3)
    