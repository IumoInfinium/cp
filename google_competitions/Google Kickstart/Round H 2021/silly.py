global d
d={}
d["01"]="2"
for i in range(1,10):
    d[f"{i}{(i+1)%10}"]=str((i+2)%10)

def solve(s):
    global tmp
    for char in d.keys():
        if char in s:
            pos=s.find(char)

            s=s[:pos]+d[char]+s[pos+2:]
            tmp=s
            solve(s)
    if(tmp ==""):
        tmp= s
t=int(input())
for i in range(t):
    n=int(input())
    s=input()
    tmp=""
    solve(s)
    print(f"Case #{i+1}: {tmp}")
    