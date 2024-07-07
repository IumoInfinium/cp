for _ in range(int(input())):
    n,k=list(map(int,input().split()))
    s=input()
    smod=[]
    for i in range(n):
        if s[i] == ':':
            smod.append(':')
        smod.append(s[i])
    iron=[]
    magnet=[]
    res=0
    for i in range(len(smod)):
        if smod[i] == "I":
            while( len(magnet)>0 and abs(magnet[0]-i)>k):
                magnet.pop(0)
            if len(magnet)>0:
                res+=1
                magnet.pop(0)
            else: iron.append(i)
        elif smod[i] == 'M':
            while( len(iron)>0 and abs(iron[0]-i)>k):
                iron.pop(0)
            if len(iron)>0:
                res+=1
                iron.pop(0)
            else: magnet.append(i)
        elif smod[i]=='X':
            while(len(magnet)!=0): magnet.pop(0)
            while(len(iron)!=0): iron.pop(0)
    print(res)