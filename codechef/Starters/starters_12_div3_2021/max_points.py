t=int(input())
for ii in range(t):
    a,b,c = list(map(int,input().split(" ")))
    x,y,z = list(map(int,input().split(" ")))
    time = 0
    score =0 

    aexists = 20*a
    bexists= 20*b
    cexists= 20*c

    while(time<=240):
        if aexists:
            for i1 in range(20):
                if time<=240:
                    time +=a
                    score +=x

            if i1 == 19:
                aexists =0
        if bexists:        
            for i2 in range(20):
                if time<=240:
                    time +=b
                    score +=y
            if i2 == 19:
                bexists=0    
        elif cexists:
            for i3 in range(20):
                if time<=240:
                    time +=c
                    score +=z
            if i3 == 19:
                cexists =0
        else:
            break
    print(score)