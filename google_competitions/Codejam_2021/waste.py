def operation(n,p):
    l=[]
    kl= [] 
    if p< n-1:
        return kl
    #l=[]
    t=0
    c=1
    for i in range(n-1,0,-1):
        c+=1

        if t+c+i-1>=p:
            r=p-t-i+1
            l.append(r)
            print(l)
            for k in range(i-1):
                l.append(1)
            t=p
            print(l)
            break

        t+=c
        l.append(c)
        print("l appended",l)
    if t<p:
        return kl
    print("operation final",l)
    return l

x=operation(7,12)
print(x)