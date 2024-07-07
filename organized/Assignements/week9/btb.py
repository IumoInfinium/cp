def mymean(d):
    n=sum(list(d.values()))
    ans=0
    for i in d: ans+=d[i]*i
    return ans//n
def mymode(d):
    l=d.items()
    l=sorted(l,key=lambda x:(-x[-1],x[0]))
    return l[0][0]
for _ in range(int(input())):
    n,q=map(int,input().split())
    l=list(map(int,input().split()))
    d={}
    for i in l:
        if i in d.keys():
            d[i]+=1
        else:
            d[i]=1
    for __ in range(q):
        x=input()
        if len(x)==1:
            if x=='2':
                print(mymean(d))
            else:
                print(mymode(d))
        else:
            a,x=map(int,x.split())
            if x in d.keys():
                d[x]+=1
            else:
                d[x]=1
            n+=1