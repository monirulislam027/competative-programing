const fs = require("fs");
const path = require("path");
function getRandomInt(min, max) {
  min = Math.ceil(min);
  max = Math.floor(max);
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

function shuffleArray(array) {
  for (let i = array.length - 1; i > 0; i--) {
    // Generate random index from 0 to i
    const j = Math.floor(Math.random() * (i + 1));

    // Swap elements array[i] and array[j]
    [array[i], array[j]] = [array[j], array[i]];
  }
  return array;
}

function generateString(val) {
  let str = "";
  for (let i = 0; i < val; i++) {
    for (let j = 0; j <= i; j++) {
      str += "* ";
    }
    str += "\n";
  }
  return str;
}

function createFiles(start, end, prefix) {
  for (let i = start; i <= end; i++) {
    const inputFileName = `input${String(i).padStart(3, "0")}.txt`;
    const inputFilePath = path.join(__dirname, "input", inputFileName); // Create path relative to script location
    fs.writeFileSync(inputFilePath, String(i)); // Create an empty file
    console.log(`Created file: ${inputFileName}`);

    const str = generateString(i);
    const outputFileName = `output${String(i).padStart(3, "0")}.txt`;
    const outputFilePath = path.join(__dirname, "output", outputFileName); // Create path relative to script location

    fs.writeFileSync(outputFilePath, str); // Create an empty file
    console.log(`Created file: ${outputFilePath}`);
    console.log("");
  }
}
// createFiles(0, 10);

const data = [4, 16];

const randomSquareNumber = [];
const randomNumber = [];

// temporary values
const squareNumber = [];
const simpleNumber = [];

for (let i = 1; i <= 100; i++) {
  squareNumber.push(i * i);
}

for (let i = 1; i <= 1000; i++) {
  if (!squareNumber.includes(i)) {
    simpleNumber.push(i);
  }
}

for (let i = 0; i < 10; i++) {
  // square number push
  let idx = getRandomInt(0, squareNumber.length - 1);
  randomSquareNumber.push(squareNumber[idx]);
  squareNumber.splice(idx, 1);
  shuffleArray(squareNumber);

  // simple number push
  let idx2 = getRandomInt(0, squareNumber.length - 1);
  randomNumber.push(simpleNumber[idx2]);
  simpleNumber.splice(idx2, 1);
  shuffleArray(simpleNumber);
}

shuffleArray(randomSquareNumber);
shuffleArray(randomNumber);

const values = [...randomNumber, 0, ...randomSquareNumber];
shuffleArray(values);

data.push(...randomNumber);

const newData = [...data, ...values];

newData.forEach((val) => console.log(`${val}`));

function createFiles2() {
  newData.forEach((val, i) => {
    const inputFileName = `input${String(i).padStart(3, "0")}.txt`;
    const inputFilePath = path.join(__dirname, "input", inputFileName); // Create path relative to script location
    fs.writeFileSync(inputFilePath, String(val)); // Create an empty file
    console.log(`Created file: ${inputFileName}`);

    const str = isPerfectSquare(val);
    const outputFileName = `output${String(i).padStart(3, "0")}.txt`;
    const outputFilePath = path.join(__dirname, "output", outputFileName); // Create path relative to script location

    fs.writeFileSync(outputFilePath, str); // Create an empty file
    console.log(`Created file: ${outputFilePath}`);
    console.log("");
  });
}

function isPerfectSquare(num) {
  if (num <= 0) return "NO"; // Negative numbers cannot be perfect squares
  const sqrt = Math.sqrt(num);
  return Number.isInteger(sqrt) ? "YES" : "NO";
}

createFiles2();
