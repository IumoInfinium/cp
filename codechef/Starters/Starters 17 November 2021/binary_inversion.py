t=int(input())
for tests in range(t):
    n,m = list(map(int,input().split(" ")))
    l=[]
    for strs in range(n):
        stri = input()
        l.append(int(stri,2))
    l.sort()
    s = ""
    for ele in l:
        s+=f"{int(str(ele),2)}"
    count =0
    for p in range(len(s)):
        if(s[p] == "1"):
            tmp=s[p:]
            for q in tmp:
                if(q=="0"): count+=1

    print(count)