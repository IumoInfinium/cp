l=list(map(int,input().split(" ")))
l.sort()
cost=0
for i in range(1,len(l)):
    cost += abs(l[i]-l[i-1])
print(cost)