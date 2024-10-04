const fs = require("fs");
const path = require("path");
function getRandomInt(min, max) {
  min = Math.ceil(min);
  max = Math.floor(max);
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

function createFiles(start, end, data) {
  const data2 = [...data];

  for (let i = start; i <= end; i++) {
    const randomInt = getRandomInt(0, data2.length - 1);
    const selectData = data2[randomInt];

    const inputFileName = `input${String(i).padStart(3, "0")}.txt`;
    const inputFilePath = path.join(__dirname, "input", inputFileName); // Create path relative to script location
    fs.writeFileSync(inputFilePath, selectData[0]); // Create an empty file
    console.log(`Created file: ${inputFileName}`);

    const outputFileName = `output${String(i).padStart(3, "0")}.txt`;
    const outputFilePath = path.join(__dirname, "output", outputFileName); // Create path relative to script location
    fs.writeFileSync(outputFilePath, selectData[1]); // Create an empty file

    console.log(`Created file: ${outputFilePath}`);
    console.log("");
    data2.slice(randomInt, 1);
  }
}

const data = [
  ["121", "true"],
  ["143", "false"],
  ["madam", "true"],
  ["eyed", "false"],
  ["131", "true"],
  ["141", "true"],
  ["151", "true"],
  ["161", "true"],
  ["171", "true"],
  ["181", "true"],
  ["191", "true"],
  ["202", "true"],
  ["212", "true"],
  ["222", "true"],
  ["232", "true"],
  ["242", "true"],
  ["252", "true"],
  ["262", "true"],
  ["272", "true"],
  ["282", "true"],
  ["292", "true"],
  ["303", "true"],
  ["313", "true"],
  ["323", "true"],
  ["333", "true"],
  ["343", "true"],
  ["353", "true"],
  ["363", "true"],
  ["level", "true"],
  ["radar", "true"],
  ["madam", "true"],
  ["civic", "true"],
  ["rotor", "true"],
  ["deified", "true"],
  ["refer", "true"],
  ["reviver", "true"],
  ["racecar", "true"],
  ["solos", "true"],
  ["stats", "true"],
  ["tenet", "true"],
  ["noon", "true"],
  ["pop", "true"],
  ["wow", "true"],
  ["mom", "true"],
  ["dad", "true"],
  ["did", "true"],
  ["eye", "true"],
  ["gig", "true"],
  ["hannah", "true"],
  ["malayalam", "true"],
  ["repaper", "true"],
  ["detartrated", "true"],
  ["aibohphobia", "true"],
  ["123", "false"],
  ["132", "false"],
  ["143", "false"],
  ["152", "false"],
  ["163", "false"],
  ["172", "false"],
  ["183", "false"],
  ["192", "false"],
  ["203", "false"],
  ["213", "false"],
  ["223", "false"],
  ["233", "false"],
  ["243", "false"],
  ["253", "false"],
  ["263", "false"],
  ["273", "false"],
  ["283", "false"],
  ["293", "false"],
  ["304", "false"],
  ["314", "false"],
  ["324", "false"],
  ["334", "false"],
  ["344", "false"],
  ["354", "false"],
  ["364", "false"],
  ["lever", "false"],
  ["rider", "false"],
  ["madman", "false"],
  ["civicd", "false"],
  ["rotorh", "false"],
  ["deifies", "false"],
  ["refers", "false"],
  ["revived", "false"],
  ["racebar", "false"],
  ["soloed", "false"],
  ["statis", "false"],
  ["tenant", "false"],
  ["nook", "false"],
  ["pops", "false"],
  ["woe", "false"],
  ["mommy", "false"],
  ["dada", "false"],
  ["died", "false"],
  ["eyed", "false"],
  ["giggle", "false"],
  ["hannahs", "false"],
  ["malayan", "false"],
  ["reappear", "false"],
  ["deart", "false"],
  ["aibophobia", "false"],
];

createFiles(0, 33, data);
