testcase = int(input())

for t in range(testcase):
    s = list(input()) 
    ans=0
    n = len(s)
    for i in range(n):
        if s[i] == s[(i+1)%n] :
            ans+=1
            if (s[i] == 'P' ):
                s[(i+1)%n] = 'S'
            elif(s[i] == 'R'):
                s[(i+1)%n] = 'P'
            elif(s[i] == 'S'):
                s[(i+1)%n] = 'R'
    print(f"Case #{t+1}: {ans}")