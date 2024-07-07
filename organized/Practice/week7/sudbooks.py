ds=[]
for _ in range(int(input())):
    st=list(map(int,input().split()))
    if st[-1]==-1:
        if(len(ds)==0):
            print("kuchbhi?")
        else:
            print(ds[-1])
            ds.pop()
    else:
        ds.append(st[-1])