const fs = require("fs")

const raw = fs.readFileSync(0, "utf8").trim().split("\n")

let T = parseInt(raw[0])
for (let tc = 1 ; tc <= T; tc++) {
    let input = raw[tc]
    let summ = 0
    for (let number of input) {
        summ += parseInt(number);
    }
    let result 
    let num2insert = 9 - summ % 9;
    let index2insert = 0
    if (num2insert === 9) {
        num2insert = 0;
        index2insert = 1;
    }

    while (index2insert < input.length) {
        if (parseInt(input[index2insert]) <= num2insert) { index2insert++}
        else {break;}
    }
    result = input.substring(0, index2insert) + num2insert + input.substring(index2insert, input.length)
    console.log(`Case #${tc}: ${result}`) 
}