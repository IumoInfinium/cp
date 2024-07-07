n,m=map(int,input().split(" "))
sf=list(map(int,input().split(" ")))
true_sf=[]
non_sf=[]
for i in range(m):
    f,p,s=input().split(" ")
    f,p=int(f),int(p)
    if f not in sf:
        non_sf.append([f,p,s])
    else:
        true_sf.append([f,p,s])
true_sf.sort(key=lambda x:x[1],reverse=True)
for i in range(len(true_sf)):
    print(true_sf[i][2])
non_sf.sort(key=lambda x:x[1],reverse=True)
for i in range(len(non_sf)):
    print(non_sf[i][2])