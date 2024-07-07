from math import ceil
n=int(input())
l={}
uids=[]
total_cost=0
for i in range(n):
    mv,uid,t=input(),input(),int(input())
    if uid in l.keys():
        l[uid].append(t)
    else:
        uids.append(uid)
        l[uid]=[t]
cost=0
print(l)
for uid in uids:
    x = ceil(((l[uid][-1]-l[uid][0])/60))
    if x>1:
        cost+= x*30
        cost+=30
    elif x==1:
        cost+=60
print(cost)

