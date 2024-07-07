# Didn't work completely....TLE in TEST-2
def generate(d):
    d=sorted(d)
    max_size=1
    for i in range(1,min(d)):
        d2=[d for d in d[i-1:]]
        size=0
        while(len(d2)>0):
            if(d2.pop(0)>=i+size):
                size+=1
        max_size=max(max_size,size)
    return max_size
ans=[]
for t in range(int(input())):
    x=input()
    d=[int(i) for i in input().split()]
    ans.append(generate(d))
for ind,val in enumerate(ans,start=1):
    print(f"Case #{ind}: {val}")