n=int(input())
l=list(map(int,input().split()))
for i in range(n):
    ans=-1
    for j in range(i+1,n):
        # print(ans,"Asd")
        if l[j]>l[i] and l[j]>ans:
            ans=l[j]
    print(ans,end=" ")
print()