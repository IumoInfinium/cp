for tt in range(int(input())):
    n=int(input())
    s=input()
    m,d="mom","dad"
    t=0
    for i in s:
        if m=="":
            print("Mom")
            break
        elif d=="":
            print("Dad")
            break
        if i == m[0]:
            m = m[1:]
        if i == d[0]:
            d=d[1:]
        if len(m)>=1 or len(d)>=1:
            t=1
    if t:
        print("Goo-Goo")