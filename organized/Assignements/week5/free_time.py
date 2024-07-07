n,m=map(int,input().split(" "))
alice=[]
bob=[]
for i in range(n):
    x,y=map(int,input().split(" "))
    alice.append([x,y])
for i in range(m):
    x,y=map(int,input().split(" "))
    bob.append([x,y])
c=0
l=0
r=0
while(l<n and r<m):
    start=-1
    if(alice[l][0] > bob[r][0]):
        start=alice[l][0]
    else:
        start=bob[r][0]

    end=-1
    if(alice[l][1]<bob[r][1]):
        end=alice[l][1]
        l+=1
    else:
        end=bob[r][1]
        r+=1
    
    c+=max(end-start,0)
print(c)