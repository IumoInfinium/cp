t=int(input())
for i in range(t):
    s=input()
    f=input()
    print(set(s))
    if(set(s)==f):
        print(f"Case #{i+1}: 0")
    else:
        print(f"Case #{i+1}: NAN")