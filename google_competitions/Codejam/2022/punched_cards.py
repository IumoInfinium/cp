for i in range(int(input())):
    print('Case #'+str(i+1)+':')
    r,c = map(int,input().split())
    for j in range(2*r+1):
        s=''
        if j == 0 :
            s='..'
            for k in range(c-1):
                s+='+-'
            s+='+'
            print(s)
        elif j == 1:
            s='..'
            for k in range(c-1):
                s+='|.'
            s+='|'
            print(s)
        elif j % 2 ==0:
            for k in range(c):
                s+='+-'
            s+='+'
            print(s)
        else:
            for k in range(c):
                s+='|.'
            s+='|'
            print(s)