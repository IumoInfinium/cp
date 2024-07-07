for tc in range(int(input())):
    print("Case #", end="")
    print(tc+1, end="")
    print(": ", end="")
    istr = input()
    pstr = input() 
    m = len(istr)   
    n = len(pstr)
    i = 0
    j = 0
    c = 0
    while(j < n and i < m):
        if(istr[i] == pstr[j]): i+=1
        else: c+=1
        j+=1
    if(i == m):
        print(c + n-j)
    else:
        print("IMPOSSIBLE")