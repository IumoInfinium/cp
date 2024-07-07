# Advent of Code - Day 1
# Basic Idea - Given an array of Z(>0), find the increase in the next element count
def window(i):
    return meas[i] + meas[i+1] + meas[i+2]

incw = [window(i) > window(i-1) for i in range(0, len(meas) - 2)]
print(sum(incw))