let a = 4;
let b = 7;
let c = "I am a \"double quoted\"";

a ++;
b += 21;
c += " String";

let d = "firstLine\n\\\'\"\tsecondLine\nthirdLine";
let e = "Jello World";
e[0] = "H"; // won't change, string immutability

let arr = ["cow", 23, 2.456];

console.log(a);
console.log(b);
console.log(c);
console.log([c.length-4]);
console.log(d);
console.log(e);
console.log(arr);
arr.push("murgi");
console.log(arr);
arr.push(["chagol", 210]);
console.log(arr);
let removedFromArray = arr.pop();
console.log(arr);
console.log(removedFromArray);
let againRemovedButFromFront = arr.shift();
console.log(arr);
console.log(againRemovedButFromFront);
// unshift is basically push_front, such a shit name
arr.unshift("cow");
console.log(arr);
