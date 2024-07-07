    if char in s:
            pos=s.find(char)

            s=s[:pos]+d[char]+s[pos+2:]
            print(s)
    