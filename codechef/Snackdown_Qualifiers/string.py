import time
start= time.time()
for _ in range(int(input())):
    s1,s2,x = input(),input(),input()
    s1pre,s2pre = [""],[""]
    count =0
    s1pre += [s1[:i+1] for i in range(len(s1)) if s1[:i+1] in x]

    s2pre += [s2[:i+1] for i in range(len(s2))  if s2[:i+1] in x]
    # for i in range(len(s1)):
    #     tmp = s1[:i+1]
    #     tmp2 =s2[:i+1]
    #     if tmp in x:
    #         s1pre.append(tmp)
    #     if tmp2 in x:
    #         s2pre.append(tmp2)
    for i in range(max(len(s1pre),len(s2pre))):
        if s1pre[i]+s2pre[i] in x:
            count +=1
    print(count)        
    # for i in s1pre:
    #     for j in s2pre:
    #         if i+j in x:
    #             count +=1
    # print(count)
end = time.time()
print(end-start)

