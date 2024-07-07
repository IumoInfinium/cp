def sum_digit(n):
    r=0
    while(n):
        r, n = r + n % 10, n // 10
    return r

def get_product(n):
    product = 1
    while (n != 0):
        product = product * (n % 10)
        n = n // 10
    return product
for t in range(int(input())):
    s = input()
    s = s.split()
    a = int(s[0])
    b = int(s[1])


    count = 0

    for num in range(a,b + 1):
        prod = get_product(num)
        summ = sum_digit(num)
        if prod % summ == 0:
            count += 1
    print(f"Case #{t + 1}: {count}")