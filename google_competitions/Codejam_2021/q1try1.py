## wORKING PASSED
## Reversort

# t= int(input())
# for i1 in range(t):
#     n=int(input())
#     l=list(map(int,input().split(" ")))
#     sum = 0
#     for i in range(0,n-1):
#         ele = min(l[i:n+1])
#         j = l.index(ele)
#         l[i:j+1] = l[i:j+1][::-1]
#         sum += (j-i+1)
#     print("Case #"+str(i1+1)+": "+str(sum))


t= int(input())
for i1 in range(t):
    n=int(input())
    l=list(map(int,input().split(" ")))
    sum = 0
    for i in range(0,n-1):
        ele = min(l[i:n+1])
        j = l.index(ele)
        l[i:j+1] = l[i:j+1][::-1]
        sum += (j-i+1)
    print("Case #"+str(i1+1)+": "+str(sum))