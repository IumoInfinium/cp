t=int(input())
for _ in range(t):
    n=int(input())
    a,b=input(),input()
    count=0
    tmp1,tmp2=0,0
    for i in range(n-1,-1,-1):
        # print("asd",i)
        if(a[i:]<b[i:]):
            count+=1
            tmp2=i
        elif(a[i:]>b[i:]):
            tmp1=i
        if(tmp2<tmp1):
            count+=1    
    print(count)
