testcase = int(input())

def solve(s):
    ans = []
    ans_sett = set()

    for c in s:
        if(c not in ans_sett):
            ans_sett.add(c)
            ans.append(c)
        elif c == ans[-1]:
            continue
        else: return False, []
    return True, ans

for t in range(testcase):
    n = int(input())
    s = list(input().split())

    state, ans = solve(s)

    if(not state):
        print(f"Case {t+1}: IMPOSSIBLE")
    else:
        print(f"Case #{t+1}:",*ans)