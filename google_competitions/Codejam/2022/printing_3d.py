def generate(p1,p2,p3):
    min_values=[]
    for i in range(4):
        min_values.append(min(p1[i],p2[i],p3[i]))

    if sum(min_values) < 1e6:
        return ["IMPOSSIBLE"]
    if sum(min_values)== 1e6:
        return min_values
    for i in range(4):
        min_values[i]=max(0,min_values[i]-int(abs(sum(min_values) -1e6)))
        if(sum(min_values)==1e6):
            return min_values
    return ["IMPOSSIBLE"]
ans = []
for _ in range(int(input())):
    p1=[int(x) for x in input().split(" ")]
    p2=[int(x) for x in input().split(" ")]
    p3=[int(x) for x in input().split(" ")]
    ans.append(generate(p1,p2,p3))
for ind,val in enumerate(ans,start=1):
    res=' '.join(map(str,val))
    print(f"Case #{ind}: {res}")