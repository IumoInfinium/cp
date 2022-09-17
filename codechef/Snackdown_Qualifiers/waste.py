for _ in range(int(input())):
    s1,s2,x =input(),input(),input()
    d={'s1pre':[],'s2pre':[]}
    c=0
    for i in range(len(s1)):
        tmp = s1[:i+1]
        if tmp in x:
            d['s1pre'].append(tmp)
    for i in range(len(s2)):
        tmp = s2[:i+1]
        if tmp in x:
            d['s2pre'].append(tmp)
    
    