for _ in range(int(input())):
    n=int(input())
    s=input()
    a=s
    c=0
    str(a).sort()
    for i in range(n):
        if a[i]!=s[i]:
            c+=1
    if(c>1):
        print("NO")
    else:
        print("YES")