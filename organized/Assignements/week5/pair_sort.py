n=int(input())
a=list(map(int,input().split(" ")))
b=list(map(int,input().split(" ")))

d={}
for i in range(n):
    p=[a[i],b[i]]
    if b[i] in d.keys():
        d[b[i]].append(a[i])
    else:
        d[b[i]]=[a[i]]
for k,v in d.items():
    d[k]=sorted(v)
res=list(sorted(d.items()))[::-1]

for i in res:
    for j in i[1]:
        print(j,i[0],sep=" ",end=" ")