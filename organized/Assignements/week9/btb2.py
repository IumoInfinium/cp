for _ in range(int(input())):
    n,q=map(int,input().split())
    l=list(map(int,input().split()))
    summ=0
    d={}
    max_freq=1
    ans=-1
    for i in l:
        summ+=i
        if i in d.keys():
            d[i]+=1
            if(max_freq<d[i]):
                max_freq=d[i]
                ans=i
            elif max_freq==d[i]:
                ans=min(ans,i)
        else:
            d[i]=1
    if ans==-1: ans=min(l)
    for __ in range(q):
        x=input()
        if(len(x)==1):
            if x=='2':
                print(summ//n)
            else:
                print(ans)
        else:
            a,x=map(int,x.split())
            l.append(x)
            summ+=x
            if x in d.keys():
                d[x]+=1
                if(max_freq< d[x]):
                    max_freq=d[x]
                    ans=x
                elif max_freq==d[x]: ans=min(ans,x)
            else:
                d[x]=1
                if ans>x and max_freq==1:
                    ans=x
            n+=1