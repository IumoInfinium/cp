import math
t=int(input())
for _ in range(t):
    n=int(input())
    tmp=n
    ans=0
    l=[]
    f=[]
    while(tmp>0):
        num=bin(tmp).replace("0b","")
        if(num==num[::-1]):
            l.append(tmp)
            print(num)
        tmp-=1
    while(ans!=n):
        i=0
        
        if(ans<n and math.gcd(l[i],ans)==1):
            f.append(l[i])
        if(i>len(l)):
            i=0
    print(l)