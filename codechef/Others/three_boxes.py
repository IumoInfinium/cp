t=int(input())
for i in range(t):
    a,b,c,d = list(map(int,input().split(" ")))
    d_tmp = d
    l=[a,b,c]
    count =1
    for k in l:
        print(f"----{k}")
        if k<=d:
            d -=k
            print(d,"k<d")
        else:
            count+=1
            d = d_tmp
            print(count,"count",d,"this -d")

    print(count)