def check(l):
    for i in range(1,len(l)):
        if l[i]%3==0:
            return i
    return 0
        

def solve(l):
    l.insert(0,'X')
    ans=0
    while True:
        x=check(l)
        if x:
            for i in range(1,len(l)):
                if i==x:
                    l[i] = int(l[i]/3)
                else:
                    l[i]= int(l[i]*5)
            ans+=1
        else:
            break
        print(l)
    return ans

t=int(input())
for _ in range(t):
    n=int(input())
    l = list(map(int,input().split(" ")))
    ans = solve(l)
    print(ans)