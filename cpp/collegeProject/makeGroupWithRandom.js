const crypto = require("crypto");
function getRandomInt(min, max) {
  if (min > max) {
    throw new Error("Min value should be less than or equal to max value");
  }

  // Calculate the range
  const range = max - min + 1;
  const byteArray = crypto.randomBytes(4);
  const randomNumber = byteArray.readUInt32BE(0);
  const randomInt = randomNumber % range;

  return min + randomInt;
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

const rolls = [
  534728, 634528, 634533, 634536, 634537, 634538, 634544, 634548, 634549,
  634551, 634552, 634554, 634555, 634556, 634559, 634564, 634565, 634568,
  634573, 634576, 634577, 634581, 634604, 634600, 634608, 634609, 634610,
  634612, 634615, 634618, 634620, 635638,
];

const team = [
  {
    name: "Alpha",
    member: [],
    leader: 534766,
  },
  {
    name: "Delta",
    member: [],
    leader: 634553,
  },
  {
    name: "Gama",
    member: [],
    leader: 634569,
  },
  {
    name: "Iota",
    member: [],
    leader: 634595,
  },
];

const teamZeta = [
  634562, 634543, 634545, 634557, 634572, 634594, 634598, 634619,
];

while (rolls.length != 0) {
  const randomRollIndex = getRandomInt(0, rolls.length - 1);

  let selectedTeamIndex;
  while (true) {
    if (selectedTeamIndex) break;
    const randomForTeam = getRandomInt(0, team.length - 1);
    const tempTeam = team[randomForTeam];
    if (tempTeam.member.length < 8) {
      selectedTeamIndex = randomForTeam;
    }
  }
  team[selectedTeamIndex].member.push(rolls[randomRollIndex]);
  rolls.splice(randomRollIndex, 1);
  shuffleArray(rolls);
  shuffleArray(team);
}

team.push({
  name: "Zeta",
  leader: teamZeta[0],
  member: teamZeta.slice(1),
});
team.map((item, idx) => {
  console.log(`Team ${idx + 1} (${item.member.length + 1})`);
  console.log("===========================");
  console.log(`${item.leader} => Team Leader`);
  item.member.sort().map((member) => {
    console.log(JSON.stringify(member));
  });
  console.log("");
});
