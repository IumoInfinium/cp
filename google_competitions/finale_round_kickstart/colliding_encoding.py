def encoder(s, mp):
    ans = ""
    for c in s :
        ans += mp[c]
    return ans

testcase = int(input())
for t in range(testcase):
    arr = list(input().split())

    mp = {}

    for i in range(len(arr)):
        mp[chr(ord('A')+i)] = arr[i]
    
    words = int(input())
    sett = set()

    for w in range(words):
        word = input()
        sett.add(encoder(word, mp))
    
    print(f"Case #{t+1}: ", "NO" if len(sett) == words else "YES")
