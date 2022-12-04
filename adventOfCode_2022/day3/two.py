f = open("input.txt","r")
reader = f.readlines()

score=0

def give_priority(c):
    if c>='a' and c<='z':
        return ord(c)-ord('a') +1
    else:
        return ord(c)-ord('A')+27

s = [
    "vJrwpWtwJgWrhcsFMMfFFhFp",
    "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
    "PmmdzqPrVvPwwTWBwg",
    "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
    "ttgJtRGJQctTZtZT",
    "CrZsJsPPZsGzwwsLwLmpwMDw",
]
member=0
groups = []
group=[]
for line in reader:
    print(member)
    line = line.strip("").strip("\n")
    if(member==2):
        group.append(line)
        groups.append(group)
        group=[]
        member =0
        continue
    group.append(line)
    member +=1
print(groups)
for each_group in groups:
    set1 = set(each_group[0])
    set2 =set(each_group[1])
    set3 = set(each_group[2])
    tmp_set = set.intersection(set1,set2)
    x = list(set.intersection(tmp_set,set3))
    print(x)
    score += give_priority(x[0])
print(score)
