for tt in range(int(input())):
    n=int(input())
    s=input()
    s1,s2="",""
    c=0
    for i in s:
        if s1=="mom":
            c=1
            break
        if s2=="dad":
            c=2
            break
        if i=="m" or i=="o":
            s1+=i
        if i=="d" or i=="a":
            s2+=i
    if c==1:
        print("Mom")
    elif c==2:
        print("Dad")
    else:
        print("Goo-Goo")