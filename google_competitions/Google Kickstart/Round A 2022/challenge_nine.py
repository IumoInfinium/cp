for tc in range(int(input())):
    s=input()
    summ=0
    for ii in s:
        summ+=int(ii)
    res=0
    num2insert=9-summ%9
    index2insert=0
    if(num2insert==9):
        num2insert=9
        index2insert=1
    while(index2insert < len(s)):
        if(int(s[index2insert]) <= num2insert):
            index2insert+=1
        else:
            break
    res=s[0:index2insert]+str(num2insert)+s[index2insert:len(s)]
    print(f'Case #{tc+1}: {res}')
