for tt in range(int(input())):
	n1=input()
	n2=input()
	f=0
	for i in range(len(n1)):
		if n1[i] == n2[i] or n1[i]=='?' or n2[i]=='?':
			f=1
		else:
			f=0
	if(f==1):
		print("Yes")
	else:
		print("No")