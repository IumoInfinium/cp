streets={}
for _ in range(int(input())):
    a,b,sname,direct=input().split()
    a,b=int(a),int(b)
    if sname in streets.keys():
        streets[sname].append(a)
        streets[sname].append(b)
    else:
        streets[sname]=[a,b]
print(streets)
for i in streets:
    streets[i].sort()
    print(f"min-{streets[i][0]} max-{streets[i][-1]}")
