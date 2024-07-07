from operator import index


n,k=map(int,input().split())
ans=1
index_st=[]
p_data=[0]
p_data+=list(map(int,input().split()))
for i in range(n,0,-1):
    while(len(index_st)>0 and (p_data[index_st[-1]]>=p_data[i])):
        index_st.pop()
    if(len(index_st)>0):
        ans=(ans*(index_st[-1]+1-i))%1000000007
    index_st.append(i)
print(ans)