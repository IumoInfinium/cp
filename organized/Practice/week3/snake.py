for tt in range(int(input())):
    n=int(input())
    s=input()
    s1=s.replace(".","")
    if s1.count("HT") == len(s1)//2 and s1.count("H")==s1.count("T"):
        print("Valid")
    else:
        print("Invalid")