t=int(input())
for i1 in range(t):
    n,c = input().split(" ")
    n = int(n)
    c= int(c)
    l=[]
    for op in range(1,n+1):
        l.append(op)
    print(l)
    j= l[-1]
    for i in range(0,n-1):
        ele = max(l[i:n])
        print("ele is ",ele)
        j= l.index(ele)

        print(" j is -",j)
        print("Reversing -",l[i:j][::-1])
        l[i:j]= l[j:i]
        print("L - ",l)

''' def sorter(l):

t= int(input())
for i1 in range(t):
    n,sums = input().split()
    n=int(n)
    l= []
    for op in range(1,n+1):
        l.append(op)
    sums= int(sums)
    for i in range(0,n-1):
        j  
        l[-i:-j]= l[-i:-j][::-1]
        sums = sums -(j-i+1)
        print(sums) '''