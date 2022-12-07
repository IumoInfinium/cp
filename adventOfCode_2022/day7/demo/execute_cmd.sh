#!/bin/bash

# this scripts executes given file of commands

# fills file with follwing size
# head -c 123123 </dev/urandom >fileName


inputFile="/mnt/d/Externals/git_repo/Personal/cp/adventOfCode_2022/day7/demo/cmds.txt"

while read -r line
do
    if[ $line -eq "cd /" ]
    then
        cd "/mnt/d/Externals/git_repo/Personal/cp/adventOfCode_2022/day7/demo/"
    else 
        eval $line
done < "$inputFile"


cd "/mnt/d/Externals/git_repo/Personal/cp/adventOfCode_2022/day7/demo/"