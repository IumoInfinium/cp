for _ in range(int(input())):
    n=int(input())
    l= set(map(int,input().split()))
    se,so=0,0
    for i in l:
        if(i>0):
            se+=i
        else:
            so+=i
    print(se,so)