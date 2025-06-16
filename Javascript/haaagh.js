"use strict";
function f1() {
    console.log("Hey, world");
}
f1();
function f2() {
    console.log("Hello world");
}
f2()
function f3(a, b, c) {
    console.log(a + b - c);
}
f3(78, 90, 100);

function f4() {
    let m = "yo";
    console.log(m);
}
f4();
function f5(a) {
    return a - 7;
}
console.log(f5(45));
// console.log(m); // will give an error

let arr = [1, 2, 3, 4, 5];
console.log("Before: " + JSON.stringify(arr));

function nextInLine(arr, item) {
    arr.push(item);
    return arr.shift();
}
let testArr = [1, 2, 3, 4, 5];
console.log("Before: " + JSON.stringify(testArr));
nextInLine(testArr, 6);
console.log("After: " + JSON.stringify(testArr));

// booleans
console.log(true);

// if statements
let tafu = 5;
if(tafu == '5') console.log("Tafu is equal to " + tafu);
if(tafu === '5') console.log("Tafuu is equal to " + tafu); // this strict equal is pretty nice
else console.log("Top is equal to " + tafu);
// there is also strict inequality
if(tafu !== '5') console.log("Ha");

console.log(2+'2');
// Math.pow

function f1() {
    
}

//https://youtu.be/PkZNo7MFNFg?feature=shared&t=3653
//https://youtu.be/Oc3nhOD5los?feature=shared&t=572
