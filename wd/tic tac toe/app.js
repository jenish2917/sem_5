let boxes = document.querySelectorAll(".box");
let resetBtn = document.querySelector("#reset");
let newGameBtn = document.querySelector("#new-btn");
let msgContainer = document.querySelector(".msg-container");
let msg = document.querySelector("#msg");

let turnO = true;
let gameOver = false;

const winPatterns = [
  [0, 1, 2],
  [3, 4, 5],
  [6, 7, 8],
  [0, 3, 6],
  [1, 4, 7],
  [2, 5, 8],
  [0, 4, 8],
  [2, 4, 6],
];

boxes.forEach((box) => {
  box.addEventListener("click", () => {
    if (gameOver) return;
    if (turnO) {
      box.textContent = "O";
      turnO = false;
    } else {
      box.textContent = "X";
      turnO = true;
    }
    box.disabled = true;
    checkWinner();
  });
});

const checkWinner = () => {
  winPatterns.forEach((pattern) => {
    let box1 = boxes[pattern[0]].textContent;
    let box2 = boxes[pattern[1]].textContent;
    let box3 = boxes[pattern[2]].textContent;
    if (box1 === box2 && box2 === box3 && box1 !== "") {
      showWinner(box1);
      gameOver = true;
    }
  });
  if (!gameOver) {
    checkDraw();
  }
};

const showWinner = (winner) => {
  msg.textContent = `Player ${winner} wins!`;
  msgContainer.classList.remove("hide");
};

const checkDraw = () => {
  let allFilled = true;
  boxes.forEach((box) => {
    if (box.textContent === "") {
      allFilled = false;
    }
  });
  if (allFilled) {
    msg.textContent = "It's a draw!";
    msgContainer.classList.remove("hide");
    gameOver = true;
  }
};

resetBtn.addEventListener("click", () => {
  boxes.forEach((box) => {
    box.textContent = "";
    box.disabled = false;
  });
  turnO = true;
  gameOver = false;
  msgContainer.classList.add("hide");
});

newGameBtn.addEventListener("click", () => {
  boxes.forEach((box) => {
    box.textContent = "";
    box.disabled = false;
  });
  turnO = true;
  gameOver = false;
  msgContainer.classList.add("hide");
});
