# cook your dish here
n=int(input())
l=[]
for i in range(n):
    x=list(map(int,input().split(" ")))
    if(i==0 or i==n-1):
        x[0]="@"
        x[-1]="@"
        for j in range(1,len(x)-1):
            x[j] = "?"
    l.append(x)
for i in range(1,n-1):
    l[i][0] = "?"
for i in range(1,n-1):
    l[i][n-1] = "?"

for i in range(n):
    for j in range(n):
        print(l[i][j],end=" ")
    print()
