# t=int(input())
# for _ in range(t):
#     n,k=list(map(int,input().split(" ")))
#     l=list(map(int,input().split(" ")))
#     tmp=l
#     f=[]
#     for i in range(1,k+1):
#         tmp=l
#         tmp=list(filter((i).__ne__,tmp))
#         ans=0
#         for j in range(1,len(tmp)):
#             if tmp[j-1]!=tmp[j]:
#                 ans+=1
#         f.append(ans)
#     for i in f:
#         print(i,end=" ")
#     print()

t=int(input())
for _ in range(t):
    n,k=list(map(int,input().split(" ")))
    l=list(map(int,input().split(" ")))
    freq={}
    for i in l:
        if i in freq.key():
            freq[i] +=1
        else:
            freq[i]=1
    for i in range(1,k+1):
        tmp = freq
        if i in tmp.keys():
            del tmp[i]
            if(len(tmp)==1):
                print(0,end=" ")
            else:
                tmp.values().__reduce__(1)