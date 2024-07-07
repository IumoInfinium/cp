T=int(input())
for i in range(T):
    global x,y
    x,y,s=input().split()
    x=int(x)
    y=int(y)
    out=0
    c=s.count("?")
    while c>0:
        t=1
        c=s.count("C?C")
        while c>0:
            s=s.replace("C?C",'CCC')
            c-=1
            t=0

        c=s.count("J?J")
        while c>0:
            s=s.replace("J?J",'JJJ')
            c-=1
            t=0

        c=s.count("J?C")
        while c>0:
            if x<y:
                s=s.replace('J?C','JCC')
            else:
                s=s.replace('J?C','JJC')
            c-=1
            t=0

        c=s.count("C?J")
        while c>0:
            if x<y:
                s=s.replace('C?J','CCJ')
            else:
                s=s.replace('C?J','CJJ')
            c-=1
            t=0

        c=s.count("J?")
        while c>0:
            s=s.replace("J?",'JJ')
            c-=1
            t=0

        c=s.count("?J")
        while c>0:
            s=s.replace("?J",'JJ')
            c-=1
            t=0

        c=s.count("C?")
        while c>0:
            s=s.replace("C?",'CC')
            c-=1
            t=0

        c=s.count("?C")
        while c>0:
            s=s.replace("?C",'CC')
            c-=1
            t=0
        
        if t==1:
            if x<y:
                s=s.replace("?","C")
            else:
                s=s.replace("?","J")
        c=s.count("?")
    out+=(s.count('CJ')*x + s.count('JC')*y)
    print('Case #'+str(i+1)+': '+str(out))