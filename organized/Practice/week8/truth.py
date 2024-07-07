for _ in range(int(input())):
    tr=int(input())
    trn=list(map(int,input().split()))
    dr=int(input())
    drn=list(map(int,input().split()))
    ts=int(input())
    tsn=list(map(int,input().split()))
    ds=int(input())
    dsn=list(map(int,input().split()))
    ft,fd=1,1
    for i in tsn:
        if i not in trn:
            ft=0
            break
    for j in dsn:
        if j not in drn:
            fd=0
            break
    if ft==1 and fd==1:
        print('yes')
    else:
        print('no')