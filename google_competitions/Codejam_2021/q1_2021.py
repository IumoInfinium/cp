## ReverseSort
t= int(input())
for i1 in range(t):
    n = int(input())
    l= list(map(int,input().split(" ")))
    sum= 0
    print("Iteration"+str(i1))
    for i in range(0,n-1):
        ele = min(l[i:n+1])
        j = l.index(ele)
        j=j-1
        print("Min at",j)
        #l[i:j] = l[i:j][::-1]
        print("l[i:j:-1]  ",l[i-1:j:-1])
        l[i-1:j] = l[i-1:j][::-1]
        print("sum" + str(sum))
        sum += j-i+1
        print(l)
    print("Case #"+str(i1+1)+": "+str(sum))
    print(l)
