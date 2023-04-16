testcase = int(input())


def solve(m,r,bulbs):
    bulbs.append(m+r)
    bulbs_used = 0

    curr_right = 0

    for i in range(len(bulbs) -1):
        if(bulbs[i+1] - r <= curr_right): continue
        if(bulbs[i] -r  > curr_right): return False, -1
        bulbs_used += 1
        curr_right = bulbs[i] + r

    if(curr_right < m): return False, -1
    return True, bulbs_used 

for t in range(testcase):
    m,r,n = list(map(int,input().split()))

    bulbs = list(map(int,input().split()))

    state, ans = solve(m,r,bulbs)

    if(state): print(f"Case #{t+1}: {ans}")
    else: print(f"Case #{t+1}: IMPOSSIBLE")