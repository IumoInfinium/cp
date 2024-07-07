for _ in range(int(input())):
    s=input()
    sscore,mscore=s.count('s'),s.count('m')
    x=mscore-sscore
    print(sscore,mscore,'---')
    if x<0:
        print('snakes')
    elif x>0:
        print('mongooses')
    else:
        print('tie')
    