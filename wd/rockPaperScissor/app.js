// making rock paper scissor
let userScore = 0;
let computerScore = 0;

const choices = document.querySelectorAll(".choice");
const messageElement = document.querySelector("#msg");

const userScoreElement = document.querySelector("#user-score");
const computerScoreElement = document.querySelector("#Computer-score");
const youChoose = document.querySelector(".userChoice");
const computerChoose = document.querySelector(".computerChoice");

const options = ["rock", "paper", "scissor"];

const computerChoice = () => {
  const random = Math.floor(Math.random() * options.length);
  return options[random];
};

const playGame = (userChoice) => {
  const computer = computerChoice();
  const outcome = getOutcome(userChoice, computer);
    youChoose.innerHTML = "You choose : " + userChoice;
    computerChoose.innerHTML = "Computer choose : " + computer;
  messageElement.textContent = outcome.message;
  messageElement.style.backgroundColor = outcome.color;

  if (outcome.winner === "user") {
    userScore++;
    userScoreElement.textContent = userScore;
  } else if (outcome.winner === "computer") {
    computerScore++;
    computerScoreElement.textContent = computerScore;
  }
};

const getOutcome = (userChoice, computerChoice) => {
  if (userChoice === computerChoice) {
    return { message: "It's a tie", color: "#405D72", winner: null };
  }

  const outcomes = {
    rock: { paper: "You lose", scissor: "You win" },
    paper: { rock: "You win", scissor: "You lose" },
    scissor: { rock: "You lose", paper: "You win" },
  };

  const outcome = outcomes[userChoice][computerChoice];
  const winner = outcome === "You win" ? "user" : "computer";
  const color = outcome === "You win" ? "green" : "red";

  return { message: outcome, color, winner };
};

choices.forEach((choice) => {
  choice.addEventListener("click", () => {
    const userChoice = choice.getAttribute("id");
    playGame(userChoice);
  });
});
