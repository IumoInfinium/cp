import sys
input = sys.stdin.readline

for _ in range(int(input().strip())):
    n, d = map(int, input().split())
    p = list(map(int, input().split()))
    s = list(map(int, input().split()))
    arr = [(0,0)] + [(candy_price,candy_sweetness) for candy_price, candy_sweetness in zip(p,s)]
    arr.sort()
    smax = [0]
    for i in range(1,len(arr)):
        smax.append(max(smax[-1],arr[i][1]))

    left = 0
    right = len(arr)-1
    final_result = 0

    while right >= 0 and arr[right][0] > d:
        right -= 1

    while right >= 0 and left < right:
        while left + 1 < right and arr[left+1][0] + arr[right][0] <= d:
            left += 1

        final_result = max(final_result, smax[left] + arr[right][1])
        while right > 0 and arr[right-1][0] == arr[right][0]:
            right -= 1

        right -= 1

    for i in range(right, 0, -1):
        final_result = max(final_result, smax[i-1]+ arr[i][1])

    print(final_result)
