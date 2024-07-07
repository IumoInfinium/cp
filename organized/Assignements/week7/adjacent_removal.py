for _ in range(int(input())):
    s=input()
    st=[]
    res=0
    for x in s:
        if not st:
            st.append(x)
            res+=1
        else:
            d=st[-1]
            if(d==x):
                st.pop()
                res-=1
            else:
                st.append(x)
                res+=1
    print(res)